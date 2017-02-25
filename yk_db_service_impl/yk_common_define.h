/*
 * yk_common_defines.h
 *
 *  Created on: Oct 31, 2016
 *      Author: Ralph.Liu
 */

#ifndef SRC_YK_DB_SERVICE_IMPL_YK_COMMON_DEFINE_H_
#define SRC_YK_DB_SERVICE_IMPL_YK_COMMON_DEFINE_H_

#include <cstddef>
#include <string>
#include <sstream>

#include <memory>

#ifndef noexcept
	#if __cplusplus < 201103L
		#ifdef _WIN32
			#define noexcept(true) throw()
		#else
			#define noexcept(true) __attribute__((nothrow))
		#endif
	#endif
#endif

typedef std::string YKString;

struct YKDatabaseInfo{
	int32_t		Flag;
	int32_t		Port;
	YKString	Host;
	YKString	User;
	YKString	Password;
	YKString	Database;
	YKString	Charset;
	YKString	ClientIp;
	YKString	UnixSocket;
};
typedef std::shared_ptr<YKDatabaseInfo>	YKDatabaseInfoShp;

#include "yk_error_code.h"
#include "yk_database_logger.h"

#endif /* SRC_YK_DB_SERVICE_IMPL_YK_COMMON_DEFINE_H_ */

