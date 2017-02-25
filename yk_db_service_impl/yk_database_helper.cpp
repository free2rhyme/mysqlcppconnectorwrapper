/*
 * yk_database_helper.cpp
 *
 *  Created on: Oct 31, 2016
 *      Author: Ralph.Liu
 */

#include "yk_database_helper.h"
#include "yk_database_connection_pool.h"

YKErrorCode YKDatabaseHelper::prepare_statement(bool is_query, const YKString& sql_str, YKPreparedStatementShpType& prepared_statement_shp)noexcept(true){
	YKDatabaseConnectionShpType db_conn_shp;
	YKErrorCode result_code = YKDatabaseConnectionPool::instance().bind_database_conn(is_query, db_conn_shp);
	if(result_code != YK_E_SUCCESSFUL){
		YKLogError("couldn't get connection object");
		return result_code;
	}

	prepared_statement_shp.reset(new YKPreparedStatement(db_conn_shp));
	result_code = prepared_statement_shp->prepare_statement(sql_str);
	if(result_code != YK_E_SUCCESSFUL){
		YKLogError("couldn't create a new prepared_statement ");
		YKLogError(result_code);
	}

	return result_code;
}

YKDatabaseHelper& YKDatabaseHelper::instance() noexcept(true){
	static YKDatabaseHelper instance_;
	return instance_;
}

YKErrorCode YKDatabaseHelper::init() noexcept(true){
}

YKErrorCode YKDatabaseHelper::execute_update(const YKPreparedStatementShpType& prepared_statement_shp, int32_t& num_rows_affected) noexcept(true){
	return prepared_statement_shp->execute_update(num_rows_affected);
}

YKErrorCode YKDatabaseHelper::execute_query(const YKPreparedStatementShpType& prepared_statement_shp, YKDatabaseResultsetShpType& resultset_shp) noexcept(true){
	return prepared_statement_shp->execute_query(resultset_shp);
}

YKErrorCode YKDatabaseHelper::begin_setup_prepare_statement(YKPreparedStatementShpType& prepared_statement_shp) noexcept(true){
	return YK_E_SUCCESSFUL;
}

YKErrorCode YKDatabaseHelper::commit() noexcept(true){
	return YK_E_SUCCESSFUL;
}

YKErrorCode YKDatabaseHelper::rollback() noexcept(true){
	return YK_E_SUCCESSFUL;
}

YKDatabaseHelper::YKDatabaseHelper() noexcept(true){
}

YKDatabaseHelper::~YKDatabaseHelper() noexcept(true){
}


