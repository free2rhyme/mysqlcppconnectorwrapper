/*
 * yk_database_connection.h
 *
 *  Created on: Oct 31, 2016
 *      Author: Ralph.Liu
 */

#ifndef SRC_YK_DATABASE_CONNECTION_H_
#define SRC_YK_DATABASE_CONNECTION_H_

#include "yk_common_define.h"
#include "yk_database_common.h"

class YKDatabaseConnection;
typedef std::shared_ptr<YKDatabaseConnection> YKDatabaseConnectionShpType;

class YKDatabaseConnection{
	friend class YKDatabaseConnectionPool;
public:
	YKErrorCode prepare_statement(const YKString&, YKCppPreparedStatementShpType& )noexcept(true);
	YKErrorCode close()noexcept(true);
	YKErrorCode commit()noexcept(true);
	bool is_autoCommit()noexcept(true);
	bool is_closed()noexcept(true);
	bool is_readOnly()noexcept(true);
	bool is_valid()noexcept(true);
	bool reconnect()noexcept(true);
	YKErrorCode release_savepoint(YKCppSavepointShpType& savepoint_shp)noexcept(true);
	YKErrorCode rollback()noexcept(true);
	YKErrorCode rollback(YKCppSavepointShpType& savepoint_shp)noexcept(true);
	YKErrorCode set_autoCommit(bool autoCommit)noexcept(true);
	YKErrorCode set_savepoint(const YKString& name, YKCppSavepointShpType& savepoint_shp)noexcept(true);

	~YKDatabaseConnection()noexcept(true);
private:
	explicit YKDatabaseConnection(YKCppConnectionShpType&)noexcept(true);

	static YKErrorCode spawn_conn(const YKDatabaseInfoShp&, YKDatabaseConnectionShpType&)noexcept(true);

	YKDatabaseConnection(const YKDatabaseConnection&);
	YKDatabaseConnection& operator=(const YKDatabaseConnection&);
#if __cplusplus >= 201103L
	YKDatabaseConnection(YKDatabaseConnection&&);
	YKDatabaseConnection& operator=(YKDatabaseConnection&&);
#endif

private:
public:
	YKCppConnectionShpType		m_cpp_connection_shp;
};

#endif /* SRC_YK_DATABASE_CONNECTION_H_ */
