/*
 * yk_prepared_statement.cpp
 *
 *  Created on: Nov 1, 2016
 *      Author: Ralph.Liu
 *       Email: wlc2rhyme@gmail.com
 */

#include <sstream>
#include "yk_prepared_statement.h"
#include "yk_database_connection_pool.h"
#include "yk_prepared_statement_id.h"

YKPreparedStatement::YKPreparedStatement(const YKDatabaseConnectionShpType& db_conn_shp) noexcept(true):
	m_database_connection_shp(db_conn_shp){
	m_prepared_statement_id = YKPreparedStatementID::instance().get_next_id();
	std::stringstream ss;
	ss << "m_prepared_statement_id(" << m_prepared_statement_id << ")" ;

	YKLogTrace(ss.str());
}

YKPreparedStatement::~YKPreparedStatement() noexcept(true){
	release_database_connection();
}

YKErrorCode YKPreparedStatement::prepare_statement(const YKString& sql)noexcept(true){
	if(YK_E_SUCCESSFUL != m_database_connection_shp->prepare_statement(sql, m_native_prepared_statement_shp)){
		std::stringstream ss;
		ss << "m_prepared_statement_id(" << m_prepared_statement_id << ") connection(" << m_database_connection_shp->get_id() << ")"; ;
		YKLogTrace(ss.str());
		return YK_E_GENERAL_ERROR;
	} else {
		return YK_E_SUCCESSFUL;
	}
}

YKErrorCode YKPreparedStatement::release_database_connection() noexcept(true){
	if(m_database_connection_shp){
		YKDatabaseConnectionPool::instance().release_database_conn(m_database_connection_shp);
		m_database_connection_shp.reset();
	}
}

YKErrorCode YKPreparedStatement::execute_update(int32_t& num_rows_affected) noexcept(true){
	try {
		num_rows_affected = m_native_prepared_statement_shp->executeUpdate();
    } catch (sql::SQLException& e) {
		YKLogError(e.what());
		return YK_E_SQLEXECUTE_ERROR;
    } catch (std::runtime_error &e) {
		YKLogError(e.what());
		return YK_E_RUNTIME_ERROR;
    } catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
    }

    //release_database_connection();

    return YK_E_SUCCESSFUL;
}

YKErrorCode YKPreparedStatement::execute_query(YKDatabaseResultsetShpType& resultset_shp) noexcept(true){
	try{
		YKCppResultSetShpType raw_result_set_shp(m_native_prepared_statement_shp->executeQuery());
		resultset_shp.reset(new YKDatabaseResultset(raw_result_set_shp));
    } catch (sql::SQLException& e) {
		YKLogError(e.what());
		return YK_E_SQLEXECUTE_ERROR;
    } catch (std::runtime_error &e) {
		YKLogError(e.what());
		return YK_E_RUNTIME_ERROR;
    } catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
    }

    //release_database_connection();

    return YK_E_SUCCESSFUL;
}

YKErrorCode YKPreparedStatement::set_boolean(const uint16_t column_index, const bool value) noexcept(true){
	try{
		m_native_prepared_statement_shp->setBoolean(column_index, value);
	}catch(YKInvalidArgumentException& e){
		YKLogError(e.what());
		return YK_E_INVALID_PARAMETER;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}
YKErrorCode YKPreparedStatement::set_double(const uint16_t column_index, const double value) noexcept(true){
	try{
		m_native_prepared_statement_shp->setDouble(column_index, value);
	}catch(YKInvalidArgumentException& e){
		YKLogError(e.what());
		return YK_E_INVALID_PARAMETER;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}
YKErrorCode YKPreparedStatement::set_null(const uint16_t column_index) noexcept(true){
	try{
		m_native_prepared_statement_shp->setNull(column_index, 0);
	}catch(YKInvalidArgumentException& e){
		YKLogError(e.what());
		return YK_E_INVALID_PARAMETER;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}
YKErrorCode YKPreparedStatement::set_datetime(const uint16_t column_index, const YKString& value) noexcept(true){
	try{
		m_native_prepared_statement_shp->setDateTime(column_index, value);
	}catch(YKInvalidArgumentException& e){
		YKLogError(e.what());
		return YK_E_INVALID_PARAMETER;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}
YKErrorCode YKPreparedStatement::set_int32(const uint16_t column_index, const int32_t value) noexcept(true){
	try{
		m_native_prepared_statement_shp->setInt(column_index, value);
	}catch(YKInvalidArgumentException& e){
		YKLogError(e.what());
		return YK_E_INVALID_PARAMETER;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}
YKErrorCode YKPreparedStatement::set_uint32(const uint16_t column_index, const uint32_t value) noexcept(true){
	try{
		m_native_prepared_statement_shp->setUInt(column_index, value);
	}catch(YKInvalidArgumentException& e){
		YKLogError(e.what());
		return YK_E_INVALID_PARAMETER;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}
YKErrorCode YKPreparedStatement::set_int64(const uint16_t column_index, const int64_t value) noexcept(true){
	try{
		m_native_prepared_statement_shp->setInt64(column_index, value);
	}catch(YKInvalidArgumentException& e){
		YKLogError(e.what());
		return YK_E_INVALID_PARAMETER;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}
YKErrorCode YKPreparedStatement::set_uint64(const uint16_t column_index, const uint64_t value) noexcept(true){
	try{
		m_native_prepared_statement_shp->setUInt64(column_index, value);
	}catch(YKInvalidArgumentException& e){
		YKLogError(e.what());
		return YK_E_INVALID_PARAMETER;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}
YKErrorCode YKPreparedStatement::set_string(const uint16_t column_index, const YKString& value) noexcept(true){
	try{
		m_native_prepared_statement_shp->setString(column_index, value);
	}catch(YKInvalidArgumentException& e){
		YKLogError(e.what());
		return YK_E_INVALID_PARAMETER;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}
YKErrorCode YKPreparedStatement::set_string(const uint16_t column_index, const char* value) noexcept(true){
	try{
		m_native_prepared_statement_shp->setString(column_index, value);
	}catch(YKInvalidArgumentException& e){
		YKLogError(e.what());
		return YK_E_INVALID_PARAMETER;
	} catch(...){
		YKLogError("unexpected exception");
		return YK_E_GENERAL_ERROR;
	}
	return YK_E_SUCCESSFUL;
}
