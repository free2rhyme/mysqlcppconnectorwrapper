/*
 * yk_database_resultset.h
 *
 *  Created on: Nov 2, 2016
 *      Author: Ralph.Liu
 *       Email: wlc2rhyme@gmail.com
 */

#ifndef SRC_YK_DATABASE_RESULTSET_H_
#define SRC_YK_DATABASE_RESULTSET_H_

#include "yk_common_define.h"
#include "yk_database_common.h"

class YKDatabaseResultset{
public:
	explicit YKDatabaseResultset(YKCppResultSetShpType&) noexcept(true);
	~YKDatabaseResultset() noexcept(true);

	YKErrorCode find_column_index(const YKString&, uint32_t&) const noexcept(true);

//	YKErrorCode get_current_row_boolean(bool& value) const noexcept(true);
//	YKErrorCode get_current_row_double(long double& value) const noexcept(true);;
//	YKErrorCode get_current_row_int32(int32_t& value) const noexcept(true);
//	YKErrorCode get_current_row_uint32(uint32_t& value) const noexcept(true);
//	YKErrorCode get_current_row_int64(int64_t& value) const noexcept(true);
//	YKErrorCode get_current_row_uint64(uint64_t& value) const noexcept(true);
//	YKErrorCode get_current_row_string(YKString& value) const noexcept(true);

	YKErrorCode get_boolean(uint32_t, bool& value) const noexcept(true);
	YKErrorCode get_boolean(const YKString& column_label, bool& value) const noexcept(true);
	YKErrorCode get_double(const uint32_t, long double& value) const noexcept(true);
	YKErrorCode get_double(const YKString& column_label, long double& value) const noexcept(true);
	YKErrorCode get_int32(const uint32_t, int32_t& value) const noexcept(true);
	YKErrorCode get_int32(const YKString& column_label, int32_t& value) const noexcept(true);
	YKErrorCode get_uint32(const uint32_t, uint32_t& value) const noexcept(true);
	YKErrorCode get_uint32(const YKString& column_label, uint32_t& value) const noexcept(true);
	YKErrorCode get_int64(const uint32_t, int64_t& value) const noexcept(true);
	YKErrorCode get_int64(const YKString& column_label, int64_t& value) const noexcept(true);
	YKErrorCode get_uint64(const uint32_t, uint64_t& value) const noexcept(true);
	YKErrorCode get_uint64(const YKString& column_label, uint64_t& value) const noexcept(true);
	YKErrorCode get_string(const uint32_t, YKString& value) const noexcept(true);
	YKErrorCode get_string(const YKString& column_label, YKString& value) const noexcept(true);

	YKErrorCode get_row_position(size_t&) const noexcept(true);
	YKErrorCode rows_count(size_t&) const noexcept(true);

	bool is_closed() const noexcept(true);
	bool is_first_row() const noexcept(true);
	bool is_last_row() const noexcept(true);
	bool is_row_null(const uint32_t column_index) const noexcept(true);
	bool is_row_null(const YKString& column_label) const noexcept(true);

	YKErrorCode first() noexcept(true);
	YKErrorCode next() noexcept(true);
	YKErrorCode previous() noexcept(true);
	YKErrorCode close() noexcept(true);

private:
	mutable size_t			m_current_row;
	YKCppResultSetShpType	m_cpp_resultset_shp;

private:
	//noncopyable
	YKDatabaseResultset(const YKDatabaseResultset&) noexcept(true);
	YKDatabaseResultset& operator = (const YKDatabaseResultset&) noexcept(true);

#if __cplusplus >= 201103L
	YKDatabaseResultset(YKDatabaseResultset&&);
	YKDatabaseResultset& operator=(YKDatabaseResultset&&);
#endif

};

typedef std::shared_ptr<YKDatabaseResultset>	YKDatabaseResultsetShpType;

#endif /* SRC_YK_DATABASE_RESULTSET_H_ */
