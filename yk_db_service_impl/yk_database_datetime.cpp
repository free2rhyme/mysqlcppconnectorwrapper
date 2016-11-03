/*
 * yk_database_datetime.cpp
 *
 *  Created on: Nov 2, 2016
 *      Author: Ralph.Liu
 *       Email: wlc2rhyme@gmail.com
 */


#include "yk_database_datetime.h"
#include <cctype>

//Since gcc 4.8.2 doesn't support c++11 regex well enough, then...

//2002-12-12
//2002-01-01
static bool validateDate(const YKString& str) noexcept(true){
#define DATE_SIZE 10
	if(str.size() != DATE_SIZE){
		return false;
	}

	for(uint16_t i = 0; i < DATE_SIZE; ++i){
		if(i == 4 || i == 7){
			if(str.at(i) != '-'){
				return false;
			}
			continue;
		}

		if(!isdigit(str.at(i))){
			return false;
		}
	}

	if(str.at(5) == '1'){
		if((str.at(6) - '0') > 2){
			return false;
		}
	}
	if(str.at(8) == '1'){
		if((str.at(9) - '0') > 2){
			return false;
		}
	}

	return true;
}

//00:00:00
//23:59:59
static bool validateTime(const YKString& str) noexcept(true){
#define TIME_SIZE 8
	if(str.size() != TIME_SIZE){
		return false;
	}

	for(uint16_t i = 0; i < TIME_SIZE; ++i){
		if(i == 2 || i == 5){
			if(str.at(i) != ':'){
				return false;
			}
			continue;
		}

		if(!isdigit(str.at(i))){
			return false;
		}
	}
	if(str.at(0) == '2'){
		if((str.at(3) - '0') > 3){
			return false;
		}
	}
	if((str.at(0) - '0') > 2){
		return false;
	}

	if((str.at(3) - '0') > 5){
		return false;
	}

	if((str.at(6) - '0') > 5){
		return false;
	}

	return true;
}

//2012-12-12 23:59:59
static bool validateDateTime(const YKString& value, YKString& date, YKString& time) noexcept(true){
#define DATE_TIME_SIZE 19
	if(value.size() != DATE_TIME_SIZE){
		return false;
	}

	if(value.at(10) != ' '){
		return false;
	}

	date = value.substr(0, 10);
	if(!validateDate(date)){
		return false;
	}

	time = value.substr(11, 8);

	return validateTime(time);
}

YKDatabaseDateTime::YKDatabaseDateTime()noexcept(true):m_is_date_valid(false), m_is_time_valid(false) {

}

YKDatabaseDateTime::YKDatabaseDateTime(const YKString& date_time) noexcept(true):m_is_date_valid(false), m_is_time_valid(false) {
	if(validateDateTime(date_time, m_date, m_time)){
		m_is_date_valid = true;
		m_is_time_valid = true;
	}
}

YKDatabaseDateTime::YKDatabaseDateTime(const char* date_time) noexcept(true):m_is_date_valid(false), m_is_time_valid(false){
	if(date_time == nullptr){
		return;
	}
	if(validateDateTime(YKString(date_time), m_date, m_time)){
		m_is_date_valid = true;
		m_is_time_valid = true;
	}
}

YKDatabaseDateTime::~YKDatabaseDateTime() noexcept(true){

}

YKErrorCode YKDatabaseDateTime::set_date(const YKString& str) noexcept(true){
	if(validateDate(str)){
		m_date = str;
		m_is_date_valid = true;
		return YK_E_SUCCESSFUL;
	} else {
		m_date = "";
		m_is_date_valid = false;
		return YK_E_INVALID_PARAMETER;
	}
}
YKErrorCode YKDatabaseDateTime::set_time(const YKString& str) noexcept(true){
	if(validateTime(str)){
		m_time = str;
		m_is_time_valid = true;
		return YK_E_SUCCESSFUL;
	} else {
		m_time = "";
		m_is_time_valid = false;
		return YK_E_INVALID_PARAMETER;
	}
}
YKErrorCode YKDatabaseDateTime::set_date_time(const YKString& str) noexcept(true){
	if(validateDateTime(str, m_date, m_time)){
		m_is_date_valid = true;
		m_is_time_valid = true;
		return YK_E_SUCCESSFUL;
	} else {
		m_date = "";
		m_time = "";
		m_is_date_valid = false;
		m_is_time_valid = false;
		return YK_E_INVALID_PARAMETER;
	}
}

YKErrorCode YKDatabaseDateTime::set_date(const char* str) noexcept(true){
	return set_date(YKString(str));
}

YKErrorCode YKDatabaseDateTime::set_time(const char* str) noexcept(true){
	return set_time(YKString(str));
}

YKErrorCode YKDatabaseDateTime::set_date_time(const char* str) noexcept(true){
	return set_date_time(YKString(str));;
}

bool YKDatabaseDateTime::is_valid_date() const noexcept(true){
	return m_is_date_valid;
}

bool YKDatabaseDateTime::is_valid_time() const noexcept(true){
	return m_is_time_valid;
}

bool YKDatabaseDateTime::is_valid_date_time() const noexcept(true){
	return m_is_date_valid && m_is_time_valid;
}

const YKString&	YKDatabaseDateTime::get_date() const noexcept(true){
	return m_date;
}

const YKString&	YKDatabaseDateTime::get_time() const noexcept(true){
	return m_time;
}

YKString YKDatabaseDateTime::get_date_time() const noexcept(true){
	return m_date + " " + m_time;
}


YKDatabaseDateTime::YKDatabaseDateTime(const YKDatabaseDateTime& that) noexcept(true):
		m_is_date_valid(that.m_is_date_valid), m_is_time_valid(that.m_is_time_valid),
		m_date(that.m_date), m_time(that.m_time){

}
YKDatabaseDateTime& YKDatabaseDateTime::operator =(const YKDatabaseDateTime& that) noexcept(true){
	if(&that == this){
		return *this;
	}
	m_is_date_valid = that.m_is_date_valid;
	m_is_time_valid = that.m_is_time_valid;
	m_date = that.m_date;
	m_time = that.m_time;
	return *this;
}

#if __cplusplus >= 201103L
YKDatabaseDateTime::YKDatabaseDateTime(YKDatabaseDateTime&& that) noexcept(true):
		m_is_date_valid(that.m_is_date_valid), m_is_time_valid(that.m_is_time_valid),
		m_date(std::move(that.m_date)), m_time(std::move(that.m_time)){

}

YKDatabaseDateTime& YKDatabaseDateTime::operator =(YKDatabaseDateTime&& that) noexcept(true){
	if(&that == this){
		return *this;
	}
	m_is_date_valid = that.m_is_date_valid;
	m_is_time_valid = that.m_is_time_valid;
	m_date = std::move(that.m_date);
	m_time = std::move(that.m_time);
	return *this;
}
#endif
