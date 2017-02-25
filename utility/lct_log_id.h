/*
 * lct_log_id.h
 *
 *  Created on: Nov 4, 2016
 *      Author: Ralph.Liu
 *       Email: wlc2rhyme@gmail.com
 */

#ifndef SRC_UTILITY_LCT_LOG_ID_H_
#define SRC_UTILITY_LCT_LOG_ID_H_

#include "lct_unique_id.h"

class lct_log_id_t:public lct_unique_id_t{

public:
	static lct_log_id_t& instance();

private:
	lct_log_id_t();
	~lct_log_id_t();

	lct_log_id_t(const lct_log_id_t&)				= delete;
	lct_log_id_t& operator=(const lct_log_id_t&)	= delete;
	lct_log_id_t(lct_log_id_t&&)					= delete;
	lct_log_id_t& operator=(lct_log_id_t&&)			= delete;
};



#endif /* SRC_UTILITY_LCT_LOG_ID_H_ */
