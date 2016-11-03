/*
 * yk_database_helper.h
 *
 *  Created on: Oct 31, 2016
 *      Author: Ralph.Liu
 */

#ifndef SRC_YK_DATABASE_HELPER_H_
#define SRC_YK_DATABASE_HELPER_H_

#include <type_traits>
#include "yk_common_define.h"
#include "yk_database_common.h"
#include "yk_database_resultset.h"
#include "yk_prepared_statement.h"

class YKDatabaseHelper{
public:
	static YKDatabaseHelper& instance() noexcept(true);

	YKErrorCode init() noexcept(true);

	YKErrorCode prepare_statement(const YKString&, YKPreparedStatementShpType&) noexcept(true);

	template <typename...Vargs>
	static YKErrorCode sql_prepared_statement_query(YKDatabaseResultsetShpType&, const YKString& sql_str, Vargs...vargs) noexcept(true);

	template <typename...Vargs>
	static YKErrorCode sql_prepared_statement_execute(int32_t& num_rows_affected, const YKString& sql_str, Vargs...vargs) noexcept(true);

private:
	template <typename...Vargs>
	static YKErrorCode create_prepare_statement(const YKString& sql_str, YKPreparedStatementShpType& prepared_statement_shp, Vargs...vargs) noexcept(true);

	template <typename...Vargs>
	static YKErrorCode begin_setup_prepare_statement(YKPreparedStatementShpType& prepared_statement_shp, Vargs...vargs) noexcept(true);

	static YKErrorCode begin_setup_prepare_statement(YKPreparedStatementShpType& prepared_statement_shp) noexcept(true);

	template <typename T, typename...Vargs>
	static YKErrorCode setup_prepared_statement(YKPreparedStatementShpType& prepared_statement_shp, uint16_t index,const T& value, Vargs...vargs) noexcept(true);

	template <typename T, typename...Vargs>
	static YKErrorCode setup_prepared_statement(YKPreparedStatementShpType& prepared_statement_shp, const uint16_t index, const T& value) noexcept(true);

	template <typename T>
	static YKErrorCode setAnyType(YKPreparedStatementShpType& prepared_statement_shp, const uint16_t index, const T& value) noexcept(true);

	static YKErrorCode execute_update(const YKPreparedStatementShpType&, int32_t&) noexcept(true);

	static YKErrorCode execute_query(const YKPreparedStatementShpType&, YKDatabaseResultsetShpType&) noexcept(true);

	static YKErrorCode commit()noexcept(true);

	static YKErrorCode rollback()noexcept(true);

private:
	YKDatabaseHelper() noexcept(true);
	~YKDatabaseHelper() noexcept(true);

	//noncopyable
	YKDatabaseHelper(const YKDatabaseHelper&);
	YKDatabaseHelper& operator=(const YKDatabaseHelper&);
#if __cplusplus >= 201103L
	YKDatabaseHelper(YKDatabaseHelper&&);
	YKDatabaseHelper& operator=(YKDatabaseHelper&&);
#endif
};

#include "yk_database_helper.hpp"


#endif /* SRC_YK_DATABASE_HELPER_H_ */
