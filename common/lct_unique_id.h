/*
 * lct_unique_id.h
 *
 *  Created on: Nov 3, 2016
 *      Author: Ralph.Liu
 *       Email: wlc2rhyme@gmail.com
 */

#ifndef SRC_YK_DB_SERVICE_IMPL_LCT_UNIQUE_ID_H_
#define SRC_YK_DB_SERVICE_IMPL_LCT_UNIQUE_ID_H_

#include <atomic>

class lct_unique_id_t{
public:
	lct_unique_id_t();
	virtual ~lct_unique_id_t();

	uint32_t get_next_id();

	lct_unique_id_t(const lct_unique_id_t&)					= delete;
	lct_unique_id_t& operator=(const lct_unique_id_t&)		= delete;
	lct_unique_id_t(lct_unique_id_t&&)						= delete;
	lct_unique_id_t& operator=(lct_unique_id_t&&)			= delete;

protected:
	std::atomic<uint32_t>		m_id;
};



#endif /* SRC_YK_DB_SERVICE_IMPL_LCT_UNIQUE_ID_H_ */
