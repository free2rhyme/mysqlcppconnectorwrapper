/*
 * lct_log_id.cpp
 *
 *  Created on: Nov 4, 2016
 *      Author: Ralph.Liu
 *       Email: wlc2rhyme@gmail.com
 */

#include "lct_log_id.h"

lct_log_id_t& lct_log_id_t::instance(){
	static lct_log_id_t _instance;
	return _instance;
}

lct_log_id_t::lct_log_id_t(){

}

lct_log_id_t::~lct_log_id_t(){

}


