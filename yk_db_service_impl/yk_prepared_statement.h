/*
 * yk_prepared_statement.h
 *
 *  Created on: Nov 1, 2016
 *      Author: Ralph.Liu
 *       Email: wlc2rhyme@gmail.com
 */

#ifndef SRC_YK_PREPARED_STATEMENT_H_
#define SRC_YK_PREPARED_STATEMENT_H_

#include "yk_common_define.h"
#include "yk_database_connection.h"
#include "yk_database_resultset.h"

class YKPreparedStatement{
public:
	explicit YKPreparedStatement(const YKDatabaseConnectionShpType&) noexcept(true);
	~YKPreparedStatement() noexcept(true);

	YKErrorCode prepare_statement(const YKString&) noexcept(true);

	YKErrorCode execute_update(int32_t& num_rows_affected) noexcept(true);
	YKErrorCode execute_query(YKDatabaseResultsetShpType& resultset_shp) noexcept(true);

	YKErrorCode set_boolean(const uint16_t index, const bool value) noexcept(true);
	YKErrorCode set_double(const uint16_t index, const double value) noexcept(true);
	YKErrorCode set_null(const uint16_t index) noexcept(true);
	YKErrorCode set_datetime(const uint16_t index, const YKString& value) noexcept(true);
	YKErrorCode set_int32(const uint16_t index, const int32_t value) noexcept(true);
	YKErrorCode set_uint32(const uint16_t index, const uint32_t value) noexcept(true);
	YKErrorCode set_int64(const uint16_t index, const int64_t value) noexcept(true);
	YKErrorCode set_uint64(const uint16_t index, const uint64_t value) noexcept(true);
	YKErrorCode set_string(const uint16_t index, const YKString& value) noexcept(true);
	YKErrorCode set_string(const uint16_t index, const char* value) noexcept(true);
private:
	YKErrorCode release_database_connection() noexcept(true);

private:
	YKCppPreparedStatementShpType		m_native_prepared_statement_shp;
	YKDatabaseConnectionShpType			m_database_connection_shp;

private:
	YKPreparedStatement(const YKPreparedStatement&);
	YKPreparedStatement& operator=(const YKPreparedStatement&);
#if __cplusplus >= 201103L
	YKPreparedStatement(YKPreparedStatement&&);
	YKPreparedStatement& operator=(YKPreparedStatement&&);
#endif

};

typedef std::shared_ptr<YKPreparedStatement>	YKPreparedStatementShpType;

#endif /* SRC_YK_PREPARED_STATEMENT_H_ */
