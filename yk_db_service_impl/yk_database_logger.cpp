/*
 * yk_database_logger.cpp
 *
 *  Created on: Nov 4, 2016
 *      Author: Ralph.Liu
 *       Email: wlc2rhyme@gmail.com
 */


#include "yk_database_logger.h"
#include "lct_log.h"
#include "lct_log_helper.h"
#include "lct_time.h"

void YKLogger(const YKLogLevel level, const char* file_name, const int line, const std::string& log_str){

	YKLogger(level, file_name, line, log_str.c_str());

}

void YKLogger(const YKLogLevel level, const char* file_name, const int line, const char* log_str){
	do{
		std::stringstream ss;
		ss << file_name << "\t " << get_current_system_time() << "\t" << std::this_thread::get_id()  << "\t" << line << "\t" << log_str << std::endl;
		lct_log_helper_t::instance().log(lct_log(ss.str()));
	}while(0);
}

extern void YKLogger(const YKLogLevel level, const char* file_name, const int line, const YKErrorCode& log_str){
	do{
		std::stringstream ss;
		ss << file_name << "\t" << get_current_system_time() << "\t" << std::this_thread::get_id()  << "\t" << line << "\t" << log_str << std::endl;
		lct_log_helper_t::instance().log(lct_log(ss.str()));
	}while(0);
}
