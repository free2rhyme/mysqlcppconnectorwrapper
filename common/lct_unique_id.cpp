/*
 * lct_unique_id.cpp
 *
 *  Created on: Nov 3, 2016
 *      Author: Ralph.Liu
 *       Email: wlc2rhyme@gmail.com
 */

#include "lct_unique_id.h"

lct_unique_id_t::lct_unique_id_t():m_id(1){
}

lct_unique_id_t::~lct_unique_id_t(){
}

uint32_t lct_unique_id_t::get_next_id(){
	return m_id.fetch_add(1, std::memory_order_relaxed);
}

