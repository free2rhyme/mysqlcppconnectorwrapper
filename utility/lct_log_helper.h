/*
 * lct_log_helper.h
 *
 *  Created on: Nov 4, 2016
 *      Author: Ralph.Liu
 *       Email: wlc2rhyme@gmail.com
 */

#ifndef SRC_UTILITY_LCT_LOG_HELPER_H_
#define SRC_UTILITY_LCT_LOG_HELPER_H_

#include "lct_queue.h"
#include "lct_log.h"

class lct_log_helper_t{
public:
	static lct_log_helper_t& instance();

	void init();

	void log(const lct_log&);

private:
	lct_log_helper_t();
	~lct_log_helper_t();

	void run();
	void close();

	lct_log_helper_t(const lct_log_helper_t&)				= delete;
	lct_log_helper_t& operator= (const lct_log_helper_t&)	= delete;

	lct_log_helper_t(lct_log_helper_t&&)					= delete;
	lct_log_helper_t& operator= (lct_log_helper_t&&)		= delete;

private:
	typedef std::shared_ptr<std::string>		lct_log_shp_type;
	typedef lct_queue_t<lct_log_shp_type>		lct_log_queue_t;
	bool										m_is_activated;
	lct_log_queue_t								m_log_queue;
};

#endif /* SRC_UTILITY_LCT_LOG_HELPER_H_ */
