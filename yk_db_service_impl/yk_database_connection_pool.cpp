/*
 * yk_database_connection_pool.cpp
 *
 *  Created on: Oct 31, 2016
 *      Author: Ralph.Liu
 */

#include "yk_database_connection_pool.h"

YKDatabaseConnectionPool::YKDatabaseConnectionPool() noexcept(true):
m_is_query(false),m_isActive(false), m_conn_min_count(1), m_conn_max_count(30), m_conn_cur_count(7){
}

YKDatabaseConnectionPool::~YKDatabaseConnectionPool()noexcept(true){
	if(m_isActive){
		shutdown_service();
	}
}

YKDatabaseConnectionPool& YKDatabaseConnectionPool::instance(){
	static YKDatabaseConnectionPool _instance;
	return _instance;
}

YKErrorCode YKDatabaseConnectionPool::init(const YKDatabaseInfoShp& db_info_shp)noexcept(true){
	m_database_info_shp = db_info_shp;
	YKLockGuard<YKMutex> lock_guard(m_queue_mutex);
	for(uint16_t i = 0; i < m_conn_cur_count; ++i){
		YKDatabaseConnectionShpType yk_conn_scp;
		if(YK_E_SUCCESSFUL != YKDatabaseConnection::spawn_conn(m_database_info_shp, yk_conn_scp)){
			YKLogError("couldn't generate new sql connection");
			return YK_E_GENERAL_ERROR;
		} else {
			YKLogError("Just generate new sql connection");
		}
		m_conn_queue.push(yk_conn_scp);
	}
	m_isActive = true;
	return YK_E_SUCCESSFUL;
}

YKErrorCode YKDatabaseConnectionPool::shutdown_service()noexcept(true){
	if(m_isActive){
		YKLockGuard<YKMutex> lock_guard(m_queue_mutex);
		m_isActive = false;
		YKConnetionQueueType empty;
		m_conn_queue.swap(empty);
		return YK_E_SUCCESSFUL;
	}else {
		return YK_E_GENERAL_ERROR;
	}
}

YKErrorCode	YKDatabaseConnectionPool::bind_database_conn(bool is_query, YKDatabaseConnectionShpType& yk_conn_scp)noexcept(true){
	if(m_isActive){
		YKUniqueLock<YKMutex> lock(m_queue_mutex);
		while(m_conn_queue.empty() && m_isActive){
			m_queue_cond.wait(lock);
		}
		if(!m_isActive){
			return YK_E_GENERAL_ERROR;
		}

		yk_conn_scp = m_conn_queue.front();
		m_conn_queue.pop();

		m_is_query = is_query;
		std::string query;
		if(m_is_query){
			query = "Query:";
		} else {
			query = "Update:";
		}

		std::stringstream ss;
		ss << "connection(" << yk_conn_scp->get_id() << ") is bound for " << query ;
		YKLogTrace(ss.str());
		return YK_E_SUCCESSFUL;
	} else {
		YKLogError("CAUTIOUS: bind_database_conn failed");
		return YK_E_GENERAL_ERROR;
	}
}

YKErrorCode	YKDatabaseConnectionPool::release_database_conn(YKDatabaseConnectionShpType& yk_conn_scp)noexcept(true){
	if(m_isActive){
		YKLockGuard<YKMutex> lock_guard(m_queue_mutex);
		m_conn_queue.push(yk_conn_scp);
		std::stringstream ss;
		std::string query;
		if(m_is_query){
			query = "Query:";
		} else {
			query = "Update:";
		}
		ss << "connection(" << yk_conn_scp->get_id() << ") is release for " << query ;
		YKLogTrace(ss.str());
		m_is_query = false;
		m_queue_cond.notify_one();

		return YK_E_SUCCESSFUL;
	} else {
		return YK_E_GENERAL_ERROR;
	}
}

