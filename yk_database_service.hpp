/*
 * yk_database_service.hpp
 *
 *  Created on: Oct 31, 2016
 *      Author: Ralph.Liu
 */

#ifndef SRC_YK_DATABASE_SERVICE_HPP_
#define SRC_YK_DATABASE_SERVICE_HPP_
#include <cstdarg>
#include "yk_database_helper.h"
#include "yk_database_connection_pool.h"

#define MYSQL_PREPARED_STATEMENT_PLACE_HOLDER	'?'

class YKDatabaseService{
public:
	static YKErrorCode yk_database_env_setup(const YKDatabaseInfoShp& info_shp){
		YKDatabaseHelper::instance().init();
		return YKDatabaseConnectionPool::instance().init(info_shp);
	}

	template <typename...Params>
	static YKErrorCode sql_prepared_statement_query(YKDatabaseResultsetShpType& resultset_shp, const YKString& sql_str, Params...parameters){
		return YKDatabaseHelper::sql_prepared_statement_query(resultset_shp, sql_str, parameters...);
	}

	template <typename...Params>
	static YKErrorCode sql_prepared_statement_execute(int32_t& num_rows_affected, const YKString& sql_str, Params...parameters){
		return YKDatabaseHelper::sql_prepared_statement_execute(num_rows_affected, sql_str, parameters...);
	}

private:
	YKDatabaseService()				= delete;
	~YKDatabaseService()			= delete;
};


#endif /* SRC_YK_DATABASE_SERVICE_HPP_ */
