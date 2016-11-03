/*
 * yk_database_helper.hpp
 *
 *  Created on: Nov 2, 2016
 *      Author: Ralph.Liu
 *       Email: wlc2rhyme@gmail.com
 */

#ifndef SRCL_YK_DATABASE_HELPER_HPP_
#define SRCL_YK_DATABASE_HELPER_HPP_

#include <boost/any.hpp>
#include "yk_database_datetime.h"

template <typename...Vargs>
YKErrorCode YKDatabaseHelper::sql_prepared_statement_execute(int32_t& num_rows_affected, const YKString& sql_str, Vargs...vargs) noexcept(true){
	YKPreparedStatementShpType prepared_statement_shp;
	YKErrorCode result_code = create_prepare_statement(sql_str, prepared_statement_shp, vargs...);
	if(result_code != YK_E_SUCCESSFUL){
		//YKLogError("couldn't create or setup a new prepared_statement");
		return result_code;
	}

	result_code = execute_update(prepared_statement_shp, num_rows_affected);
	if(result_code != YK_E_SUCCESSFUL){
		//YKLogError("couldn't execute update prepared_statement");
		return result_code;
	}

	return YK_E_SUCCESSFUL;
}

template <typename...Vargs>
YKErrorCode YKDatabaseHelper::sql_prepared_statement_query(YKDatabaseResultsetShpType& resultset_shp, const YKString& sql_str,Vargs...vargs) noexcept(true){
	YKPreparedStatementShpType prepared_statement_shp;
	YKErrorCode result_code = create_prepare_statement(sql_str, prepared_statement_shp, vargs...);
	if(result_code != YK_E_SUCCESSFUL){
		//YKLogError("couldn't create or setup a new prepared_statement");
		return result_code;
	}

	result_code = execute_query(prepared_statement_shp, resultset_shp);
	if(result_code != YK_E_SUCCESSFUL){
		//YKLogError("couldn't execute query prepared_statement");
		return result_code;
	}
	return YK_E_SUCCESSFUL;
}

template <typename...Vargs>
YKErrorCode YKDatabaseHelper::create_prepare_statement(const YKString& sql_str, YKPreparedStatementShpType& prepared_statement_shp, Vargs...vargs) noexcept(true){

	YKErrorCode result_code = YKDatabaseHelper::instance().prepare_statement(sql_str, prepared_statement_shp);
	if(result_code != YK_E_SUCCESSFUL){
		//YKLogError("couldn't create a new prepared_statement");
		return result_code;
	}
	result_code = begin_setup_prepare_statement(prepared_statement_shp, vargs...);
	if(result_code != YK_E_SUCCESSFUL){
		//YKLogError("couldn't setup prepared_statement");
		return result_code;
	}
	return YK_E_SUCCESSFUL;
}

template <typename...Vargs>
YKErrorCode YKDatabaseHelper::begin_setup_prepare_statement(YKPreparedStatementShpType& prepared_statement_shp, Vargs...vargs) noexcept(true){
	return setup_prepared_statement(prepared_statement_shp, 1, vargs...);
}

template <typename T, typename...Vargs>
YKErrorCode YKDatabaseHelper::setup_prepared_statement(YKPreparedStatementShpType& prepared_statement_shp, uint16_t index, const T& value, Vargs...vargs) noexcept(true){
	setAnyType(prepared_statement_shp, index++, value);
	return setup_prepared_statement(prepared_statement_shp, index, vargs...);
}

template <typename T, typename...Vargs>
YKErrorCode YKDatabaseHelper::setup_prepared_statement(YKPreparedStatementShpType& prepared_statement_shp, const uint16_t index, const T& value) noexcept(true){
	setAnyType(prepared_statement_shp, index, value);
	return YK_E_SUCCESSFUL;
}

template <typename T>
YKErrorCode YKDatabaseHelper::setAnyType(YKPreparedStatementShpType& prepared_statement_shp, const uint16_t index, const T& value) noexcept(true){
	if(typeid(decltype(value)) == typeid(bool)){
		prepared_statement_shp->set_boolean(index, boost::any_cast<bool>(value));
	} else if(typeid(decltype(value)) == typeid(double)){
		prepared_statement_shp->set_double(index,  boost::any_cast<double>(value));
	} else if(typeid(decltype(value)) == typeid(nullptr)){
		prepared_statement_shp->set_null(index);
	} else if(typeid(decltype(value)) == typeid(YKDatabaseDateTime)){
		const YKDatabaseDateTime yk_date_time = boost::any_cast<YKDatabaseDateTime>(value);
		prepared_statement_shp->set_datetime(index,  yk_date_time.get_date_time());
	} else if(typeid(decltype(value)) == typeid(int32_t)){
		prepared_statement_shp->set_int32(index,  boost::any_cast<int32_t>(value));
	} else if(typeid(decltype(value)) == typeid(uint32_t)){
		prepared_statement_shp->set_uint32(index,  boost::any_cast<uint32_t>(value));
	} else if(typeid(decltype(value)) == typeid(int64_t)){
		prepared_statement_shp->set_int64(index,  boost::any_cast<int64_t>(value));
	} else if(typeid(decltype(value)) == typeid(uint64_t)){
		prepared_statement_shp->set_uint64(index,  boost::any_cast<uint64_t>(value));
	} else if(typeid(decltype(value)) == typeid(YKString)){
		prepared_statement_shp->set_string(index,  boost::any_cast<YKString>(value));
	} else if(typeid(decltype(value)) == typeid(const char*)){
		prepared_statement_shp->set_string(index,  boost::any_cast<const char*>(value));
	} else if(typeid(decltype(value)) == typeid(char*)){
		prepared_statement_shp->set_string(index,  boost::any_cast<char*>(value));
	} else {
		YKLogError("unexpected type");
		return YK_E_INVALID_PARAMETER;
	}
	return YK_E_SUCCESSFUL;
}

#endif /* SRCL_YK_DATABASE_HELPER_HPP_ */
