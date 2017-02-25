/*
 * lct_semaphore.h
 *
 *  Created on: Nov 2, 2016
 *      Author: Ralph.Liu
 *       Email: wlc2rhyme@gmail.com
 */

#ifndef TEST_COMMON_LCT_SEMAPHORE_H_
#define TEST_COMMON_LCT_SEMAPHORE_H_

#include <memory>
#include <mutex>
#include <condition_variable>

class lct_semaphore_t{
public:
	explicit lct_semaphore_t(const int32_t threshold);
	~lct_semaphore_t();

	void wait();
	void notify();

private:
	lct_semaphore_t(const lct_semaphore_t&)				= delete;
	lct_semaphore_t& operator=(const lct_semaphore_t&)	= delete;
	lct_semaphore_t(lct_semaphore_t&&)					= delete;
	lct_semaphore_t& operator=(lct_semaphore_t&&)		= delete;

private:
	int32_t					m_count;
	int32_t					m_threshold;
	std::mutex				m_mutex;
	std::condition_variable	m_cond;
};

typedef std::shared_ptr<lct_semaphore_t>		lct_semaphore_shp_t;

#endif /* TEST_COMMON_LCT_SEMAPHORE_H_ */
