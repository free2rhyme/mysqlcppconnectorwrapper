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

#include <memory>
#include <mutex>
#include <condition_variable>

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
