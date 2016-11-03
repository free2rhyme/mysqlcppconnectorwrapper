/*
 * yk_database_datetime.h
 *
 *  Created on: Nov 2, 2016
 *      Author: Ralph.Liu
 *       Email: wlc2rhyme@gmail.com
 */

#ifndef SRC_YK_DATABASE_DATETIME_H_
#define SRC_YK_DATABASE_DATETIME_H_

#include "yk_common_define.h"

class YKDatabaseDateTime{
public:
	YKDatabaseDateTime() noexcept(true);

	explicit YKDatabaseDateTime(const YKString& date_time) noexcept(true);
	explicit YKDatabaseDateTime(const char* date_time) noexcept(true);
	~YKDatabaseDateTime() noexcept(true);


	YKDatabaseDateTime(const YKDatabaseDateTime&) noexcept(true);
	YKDatabaseDateTime& operator =(const YKDatabaseDateTime&) noexcept(true);

#if __cplusplus >= 201103L
	YKDatabaseDateTime(YKDatabaseDateTime&&) noexcept(true);
	YKDatabaseDateTime& operator =(YKDatabaseDateTime&&) noexcept(true);
#endif

	YKErrorCode set_date(const YKString&) noexcept(true);
	YKErrorCode set_time(const YKString&) noexcept(true);
	YKErrorCode set_date_time(const YKString&) noexcept(true);

	YKErrorCode set_date(const char*) noexcept(true);
	YKErrorCode set_time(const char*) noexcept(true);
	YKErrorCode set_date_time(const char*) noexcept(true);

	bool is_valid_date() const noexcept(true);
	bool is_valid_time() const noexcept(true);
	bool is_valid_date_time() const noexcept(true);

	const YKString&	get_date() const noexcept(true);
	const YKString&	get_time() const noexcept(true);
	YKString	get_date_time() const noexcept(true);

private:
	bool			m_is_date_valid;
	bool			m_is_time_valid;
	YKString		m_date;
	YKString		m_time;
};

#endif /* SRC_YK_DATABASE_DATETIME_H_ */
