/*
 * yk_error_code.h
 *
 *  Created on: Oct 31, 2016
 *      Author: Ralph.Liu
 */

#ifndef SRC_YK_ERROR_CODE_H_
#define SRC_YK_ERROR_CODE_H_

enum YKErrorCode{
	YK_E_SUCCESSFUL					= 0,
	YK_E_GENERAL_ERROR				= 1,
	YK_E_SQLEXECUTE_ERROR			= 2,
	YK_E_SQLQUERY_ERROR				= 3,
	YK_E_MEMORY_AllOC_ERROR			= 4,
	YK_E_RUNTIME_ERROR				= 5,
	YK_E_INVALID_PARAMETER			= 6
};


#endif /* SRC_YK_ERROR_CODE_H_ */

