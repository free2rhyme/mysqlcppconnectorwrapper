/*
 * lct_semaphore.cpp
 *
 *  Created on: Nov 2, 2016
 *      Author: Ralph.Liu
 *       Email: wlc2rhyme@gmail.com
 */

#include "lct_semaphore.h"

lct_semaphore_t::lct_semaphore_t(const int32_t threshold):m_count(0), m_threshold(threshold){
}

lct_semaphore_t::~lct_semaphore_t(){

}

void lct_semaphore_t::wait(){
	std::unique_lock<std::mutex> lck(m_mutex);
	m_cond.wait(lck, [this]{ return this->m_count >= this->m_threshold; });
}

void lct_semaphore_t::notify(){
	std::lock_guard<std::mutex> lck_guard(m_mutex);
	m_count++;
	m_cond.notify_all();
}



