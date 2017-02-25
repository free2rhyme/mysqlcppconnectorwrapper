/*
 * lct_log.h
 *
 *  Created on: Nov 4, 2016
 *      Author: Ralph.Liu
 *       Email: wlc2rhyme@gmail.com
 */

#ifndef SRC_UTILITY_LCT_LOG_H_
#define SRC_UTILITY_LCT_LOG_H_

#include <string>

class lct_log{

public:
	explicit lct_log(const std::string&);
	~lct_log();

	lct_log(const lct_log&);
	lct_log& operator=(const lct_log&);
	lct_log(lct_log&&);
	lct_log& operator=(lct_log&&);


	const char* c_str() const;

private:
	uint32_t			m_log_id;
	std::string			m_log_str;

};



#endif /* SRC_UTILITY_LCT_LOG_H_ */
