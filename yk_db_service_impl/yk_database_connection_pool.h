/*
 * yk_database_connection_pool.h
 *
 *  Created on: Oct 31, 2016
 *      Author: Ralph.Liu
 */

#ifndef SRC_YK_DATABASE_CONNECTION_POOL_H_
#define SRC_YK_DATABASE_CONNECTION_POOL_H_

#include <queue>
#include <list>

#include "yk_common_define.h"
#include "yk_database_connection.h"

class YKDatabaseConnectionPool{
public:
	static YKDatabaseConnectionPool& instance();
	YKErrorCode init(const YKDatabaseInfoShp&) noexcept(true);
	YKErrorCode shutdown_service() noexcept(true);
	YKErrorCode	bind_database_conn(bool is_query, YKDatabaseConnectionShpType& conn_shp) noexcept(true);
	YKErrorCode	release_database_conn(YKDatabaseConnectionShpType& conn_shp) noexcept(true);
private:
	YKDatabaseConnectionPool() noexcept(true);
	~YKDatabaseConnectionPool() noexcept(true);

	//noncopyable
	YKDatabaseConnectionPool(const YKDatabaseConnectionPool&);
	YKDatabaseConnectionPool& operator=(const YKDatabaseConnectionPool&);

#if __cplusplus >= 201103L
	YKDatabaseConnectionPool(YKDatabaseConnectionPool&&);
	YKDatabaseConnectionPool& operator=(YKDatabaseConnectionPool&&);
#endif

private:
	bool					m_isActive;
	bool					m_is_query;
	const uint16_t			m_conn_min_count;
	const uint16_t			m_conn_max_count;
	uint16_t				m_conn_cur_count;

	YKMutex					m_queue_mutex;
	YKConditionVariable		m_queue_cond;

	YKDatabaseInfoShp		m_database_info_shp;
	typedef	std::queue<YKDatabaseConnectionShpType, std::list<YKDatabaseConnectionShpType> > YKConnetionQueueType;
	YKConnetionQueueType	m_conn_queue;
};

#endif /* SRC_YK_DATABASE_CONNECTION_POOL_H_ */
