/*
 * yk_logger.h
 *
 *  Created on: Oct 31, 2016
 *      Author: Ralph.Liu
 */

#ifndef SRC_YK_DATABASE_LOGGER_H_
#define SRC_YK_DATABASE_LOGGER_H_

#define YKLogTrace(s) std::cout << __FILE__ << "\t" << __PRETTY_FUNCTION__ << "\t" << __LINE__ << " " << s << std::endl << std::endl
//#define YKLogError(s) std::cout << __FILE__ << "\t" << __PRETTY_FUNCTION__ << "\t" << __LINE__ << " " << s << std::endl
#define YKLogError(s, ...) std::cout << __FILE__ << "\t" << __PRETTY_FUNCTION__ << "\t" << __LINE__ << " " << s << std::endl

#endif /* SRC_YK_DATABASE_LOGGER_H_ */
