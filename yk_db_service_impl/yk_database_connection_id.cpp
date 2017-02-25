/*
 * yk_database_connection_id.cpp
 *
 *  Created on: Nov 3, 2016
 *      Author: Ralph.Liu
 *       Email: wlc2rhyme@gmail.com
 */


#include "yk_database_connection_id.h"


YKDatabaseConnectionID& YKDatabaseConnectionID::instance(){
	static YKDatabaseConnectionID _instance;
	return _instance;
}

YKDatabaseConnectionID::YKDatabaseConnectionID(){

}

YKDatabaseConnectionID::~YKDatabaseConnectionID(){

}

