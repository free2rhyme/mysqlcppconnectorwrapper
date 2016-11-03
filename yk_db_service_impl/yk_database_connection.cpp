/*
 * yk_database_connection.cpp
 *
 *  Created on: Oct 31, 2016
 *      Author: Ralph.Liu
 */
#include <sstream>
#include <mysql_driver.h>
#include "yk_database_connection.h"

static const std::string CreateSqlUrl(const std::string& host_ip, const int32_t port, const char* protocol = "tcp"){
    std::stringstream ss;
    ss << protocol << "://" << host_ip << ":" << port;
    return ss.str();
}

static inline YKCppDriver* GetMySQLCppDriver(){
	return sql::mysql::get_driver_instance();
}

YKDatabaseConnection::YKDatabaseConnection(YKCppConnectionShpType& cpp_conn_Shp) noexcept(true):
		m_cpp_connection_shp(cpp_conn_Shp){
	assert(m_cpp_connection_shp);
	//m_cpp_connection_shp->setAutoCommit(false);
}

YKDatabaseConnection::~YKDatabaseConnection()noexcept(true){
	YKLogError("CAUTIOUS: YKDatabaseConnection is being destructed");
	close();
}

YKErrorCode YKDatabaseConnection::close()noexcept(true){
	try{
		m_cpp_connection_shp->close();
	} catch(YKSQLException& e){
		YKLogError(e.what());
		return YK_E_SQLEXECUTE_ERROR;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}

YKErrorCode YKDatabaseConnection::prepare_statement(const YKString& sql, YKCppPreparedStatementShpType& native_prepared_statement_shp)noexcept(true){
	try{
		native_prepared_statement_shp.reset(m_cpp_connection_shp->prepareStatement(sql));
	} catch(YKSQLException& e){
		YKLogError(e.what());
		return YK_E_SQLEXECUTE_ERROR;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}

YKErrorCode YKDatabaseConnection::commit()noexcept(true){
	try{
		m_cpp_connection_shp->commit();
	} catch(YKSQLException& e){
		YKLogError(e.what());
		return YK_E_SQLEXECUTE_ERROR;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}

bool YKDatabaseConnection::is_autoCommit()noexcept(true){
	try{
		m_cpp_connection_shp->getAutoCommit();
	} catch(YKSQLException& e){
		YKLogError(e.what());
		return YK_E_SQLEXECUTE_ERROR;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}

bool YKDatabaseConnection::is_closed()noexcept(true){
	bool isClosedFlag = false;
	try{
		isClosedFlag = m_cpp_connection_shp->isClosed();
	} catch(YKSQLException& e){
		YKLogError(e.what());
		return false;
	} catch(...){
		YKLogError("unexpected exception");
		return false;
	}
	return isClosedFlag;
}

bool YKDatabaseConnection::is_readOnly()noexcept(true){
	bool resultFlag = false;
	try{
		resultFlag = m_cpp_connection_shp->isReadOnly();
	} catch(YKSQLException& e){
		YKLogError(e.what());
		return false;
	} catch(...){
		YKLogError("unexpected exception");
		return false;
	}
	return resultFlag;
}

bool YKDatabaseConnection::is_valid()noexcept(true){
	bool resultFlag = false;
	try{
		resultFlag = m_cpp_connection_shp->isValid();
	} catch(YKSQLException& e){
		YKLogError(e.what());
		return false;
	} catch(...){
		YKLogError("unexpected exception");
		return false;
	}
	return resultFlag;
}
bool YKDatabaseConnection::reconnect()noexcept(true){
	bool resultFlag = false;
	try{
		resultFlag = m_cpp_connection_shp->reconnect();
	} catch(YKSQLException& e){
		YKLogError(e.what());
		return false;
	} catch(...){
		YKLogError("unexpected exception");
		return false;
	}
	return resultFlag;
}

YKErrorCode YKDatabaseConnection::release_savepoint(YKCppSavepointShpType& savepoint_shp)noexcept(true){
	try{
		m_cpp_connection_shp->releaseSavepoint(savepoint_shp.get());
	} catch(YKSQLException& e){
		YKLogError(e.what());
		return YK_E_SQLEXECUTE_ERROR;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}

YKErrorCode YKDatabaseConnection::rollback()noexcept(true){
	try{
		m_cpp_connection_shp->rollback();
	} catch(YKSQLException& e){
		YKLogError(e.what());
		return YK_E_SQLEXECUTE_ERROR;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}

YKErrorCode YKDatabaseConnection::rollback(YKCppSavepointShpType& savepoint_shp)noexcept(true){
	try{
		m_cpp_connection_shp->rollback(savepoint_shp.get());
	} catch(YKSQLException& e){
		YKLogError(e.what());
		return YK_E_SQLEXECUTE_ERROR;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}

YKErrorCode YKDatabaseConnection::set_autoCommit(bool autoCommit)noexcept(true){
	try{
		m_cpp_connection_shp->setAutoCommit(autoCommit);
	} catch(YKSQLException& e){
		YKLogError(e.what());
		return YK_E_SQLEXECUTE_ERROR;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}

YKErrorCode YKDatabaseConnection::set_savepoint(const YKString& name, YKCppSavepointShpType& savepoint_shp)noexcept(true){
	try{
		savepoint_shp.reset(m_cpp_connection_shp->setSavepoint(name));
	} catch(YKSQLException& e){
		YKLogError(e.what());
		return YK_E_SQLEXECUTE_ERROR;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}

YKErrorCode YKDatabaseConnection::spawn_conn(const YKDatabaseInfoShp& db_info_shp, YKDatabaseConnectionShpType& yk_conn_scp)noexcept(true){
	try{
		YKCppConnectionShpType fresh_conn(GetMySQLCppDriver()->connect(CreateSqlUrl(db_info_shp->Host, db_info_shp->Port), db_info_shp->User, db_info_shp->Password));
		YKDatabaseConnection* yk_conn_ptr = new(std::nothrow) YKDatabaseConnection(fresh_conn);
		if(yk_conn_ptr == NULL){
			//critical error;
			return YK_E_MEMORY_AllOC_ERROR;
		}
		yk_conn_scp.reset(yk_conn_ptr);
	} catch(YKSQLException& e){
		YKLogError(e.what());
		return YK_E_SQLEXECUTE_ERROR;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}

