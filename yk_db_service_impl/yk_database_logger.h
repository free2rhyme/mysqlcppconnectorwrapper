/*
 * yk_logger.h
 *
 *  Created on: Oct 31, 2016
 *      Author: Ralph.Liu
 */

#ifndef SRC_YK_DATABASE_LOGGER_H_
#define SRC_YK_DATABASE_LOGGER_H_

#include <thread>
#include <sstream>
#include "yk_error_code.h"

//#define YKLogTrace(s) std::cout << __FILE__ << "\t" << std::this_thread::get_id()  << "\t" << __LINE__ << " " << s << std::endl << std::endl
//#define YKLogError(s) std::cout << __FILE__ << "\t" << __PRETTY_FUNCTION__ << "\t" << __LINE__ << " " << s << std::endl
//#define YKLogError(s, ...) std::cout << __FILE__ << "\t" << std::this_thread::get_id()  << "\t" << __LINE__ << " " << s << std::endl
//
//#define YKLogTrace(s, ...) do{ \
//	std::stringstream ss;\
//	ss << __FILE__ << "\t\t" << std::this_thread::get_id()  << "\t\t" << __LINE__ << "\t" << s << std::endl; \
//	lct_log_helper_t::instance().log(lct_log(ss.str())); \
//}while(0);
//
//#define YKLogError(s, ...) do{ \
//	std::stringstream ss;\
//	ss << __FILE__ << "\t\t" << std::this_thread::get_id()  << "\t\t" << __LINE__ << "\t" << s << std::endl; \
//	lct_log_helper_t::instance().log(lct_log(ss.str())); \
//}while(0);

enum YKLogLevel{
	YKLogTrace		= 0,
	YKLogError
};

extern void YKLogger(const YKLogLevel, const char* file_name, const int line, const YKErrorCode& log_str);

extern void YKLogger(const YKLogLevel, const char* file_name, const int line, const std::string& log_str);
extern void YKLogger(const YKLogLevel, const char* file_name, const int line, const char* log_str);
#define YKLogTrace(s) YKLogger(YKLogTrace, __FILE__, __LINE__, s);
//#define YKLogError(s) std::cout << __FILE__ << "\t" << __PRETTY_FUNCTION__ << "\t" << __LINE_ << " " << s << std::endl
#define YKLogError(s) YKLogger(YKLogError, __FILE__, __LINE__, s);

#endif /* SRC_YK_DATABASE_LOGGER_H_ */
