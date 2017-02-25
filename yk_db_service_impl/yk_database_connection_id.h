/*
 * yk_database_connection_id.h
 *
 *  Created on: Nov 3, 2016
 *      Author: Ralph.Liu
 *       Email: wlc2rhyme@gmail.com
 */

#ifndef SRC_YK_DB_SERVICE_IMPL_YK_DATABASE_CONNECTION_ID_H_
#define SRC_YK_DB_SERVICE_IMPL_YK_DATABASE_CONNECTION_ID_H_

#include "lct_unique_id.h"

class YKDatabaseConnectionID:public lct_unique_id_t{
public:
	static YKDatabaseConnectionID& instance();

private:
	YKDatabaseConnectionID();
	~YKDatabaseConnectionID();

	YKDatabaseConnectionID(const YKDatabaseConnectionID&)				= delete;
	YKDatabaseConnectionID& operator=(const YKDatabaseConnectionID&)	= delete;
	YKDatabaseConnectionID(YKDatabaseConnectionID&&)					= delete;
	YKDatabaseConnectionID& operator=(YKDatabaseConnectionID&&)			= delete;
};



#endif /* SRC_YK_DB_SERVICE_IMPL_YK_DATABASE_CONNECTION_ID_H_ */
