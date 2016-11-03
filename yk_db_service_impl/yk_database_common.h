/*
 * yk_database_common.h
 *
 *  Created on: Oct 31, 2016
 *      Author: Ralph.Liu
 */

#ifndef SRC_YK_DATABASE_COMMON_H_
#define SRC_YK_DATABASE_COMMON_H_

#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>

#if __cplusplus < 201103L
	#include <boost/shared_ptr.hpp>
	#include <boost/thread/mutex.hpp>
	#include <boost/thread/condition_variable.hpp>
#else
	#include <memory>
	#include <mutex>
	#include <condition_variable>
#endif

typedef sql::Connection                         	NativeCppConnection;
typedef sql::PreparedStatement                  	NativeCppPreparedStatement;
typedef sql::Statement                          	NativeCppStatement;
typedef sql::Driver                            		NativeCppDriver;
typedef sql::Savepoint								NativeSavepoint;
typedef sql::ResultSet								NativeResultSet;
typedef sql::SQLException							NativeSQLException;
typedef sql::InvalidArgumentException				NativeSQLInvalidArgumentException;

typedef NativeCppConnection                     	YKCppConnection;
typedef NativeCppPreparedStatement              	YKCppPreparedStatement;
typedef NativeCppStatement                      	YKCppStatement;
typedef NativeCppDriver                        	 	YKCppDriver;
typedef NativeSavepoint								YKSavepoint;
typedef NativeResultSet								YKNativeResultSet;
typedef NativeSQLException							YKSQLException;
typedef NativeSQLInvalidArgumentException			YKInvalidArgumentException;

#if __cplusplus < 201103L
	#ifndef std::shared_ptr
		#define std::shared_ptr 		boost::shared_ptr
	#endif
	#ifndef std::mutex
		#define std::mutex      		boost::mutex
	#endif
	#ifndef  std::unique_lock
		#define std::unique_lock 		boost::unique_lock
	#endif
	#ifndef std::condition_variable
		#define std::condition_variable boost::condition_variable
	#endif
#endif

typedef std::shared_ptr<YKCppConnection>          YKCppConnectionShpType;
typedef std::shared_ptr<YKCppPreparedStatement>   YKCppPreparedStatementShpType;
typedef std::shared_ptr<YKCppStatement>           YKCppStatementShpType;
typedef std::shared_ptr<YKSavepoint>              YKCppSavepointShpType;
typedef std::shared_ptr<YKNativeResultSet>		  YKCppResultSetShpType;

#define YKMutex				std::mutex
#define YKUniqueLock		std::unique_lock
#define YKLockGuard			std::lock_guard
#define YKConditionVariable	std::condition_variable

#endif /* SRC_YK_DATABASE_COMMON_H_ */
