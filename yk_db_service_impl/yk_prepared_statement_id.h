/*
 * yk_prepared_statement_id.h
 *
 *  Created on: Nov 3, 2016
 *      Author: Ralph.Liu
 *       Email: wlc2rhyme@gmail.com
 */

#ifndef SRC_YK_PREPARED_STATEMENT_ID_H_
#define SRC_YK_PREPARED_STATEMENT_ID_H_

#include "lct_unique_id.h"

class YKPreparedStatementID:public lct_unique_id_t{
public:
	static YKPreparedStatementID& instance();

private:
	YKPreparedStatementID();
	~YKPreparedStatementID();

	YKPreparedStatementID(const YKPreparedStatementID&)				= delete;
	YKPreparedStatementID& operator=(const YKPreparedStatementID&)	= delete;
	YKPreparedStatementID(YKPreparedStatementID&&)					= delete;
	YKPreparedStatementID& operator=(YKPreparedStatementID&&)		= delete;
};



#endif /* SRC_YK_PREPARED_STATEMENT_ID_H_ */
