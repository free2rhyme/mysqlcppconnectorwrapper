/*
 * yk_prepared_statement_id.cpp
 *
 *  Created on: Nov 3, 2016
 *      Author: Ralph.Liu
 *       Email: wlc2rhyme@gmail.com
 */


#include "../../src/yk_db_service_impl/yk_prepared_statement_id.h"


YKPreparedStatementID& YKPreparedStatementID::instance(){
	static YKPreparedStatementID _instance;
	return _instance;
}

YKPreparedStatementID::YKPreparedStatementID(){

}

YKPreparedStatementID::~YKPreparedStatementID(){

}

