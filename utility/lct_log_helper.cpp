/*
 * lct_log_helper.cpp
 *
 *  Created on: Nov 4, 2016
 *      Author: Ralph.Liu
 *       Email: wlc2rhyme@gmail.com
 */
#include <thread>
#include <iostream>
#include "lct_log_helper.h"

lct_log_helper_t& lct_log_helper_t::instance(){
	static lct_log_helper_t _instance;
	return _instance;
}

void lct_log_helper_t::init(){
	std::thread async_thread(&lct_log_helper_t::run, this);
	async_thread.detach();
	m_is_activated = true;
}

void lct_log_helper_t::log(const lct_log& log){
	m_log_queue.enqueue(lct_log_shp_type(new std::string(log.c_str())));
}

lct_log_helper_t::lct_log_helper_t():m_is_activated(false){

}

lct_log_helper_t::~lct_log_helper_t(){
	close();
}


void lct_log_helper_t::run(){
	std::cout << __PRETTY_FUNCTION__ << "\t" << __LINE__ << std::endl;
	while(!m_is_activated){
		continue;
	}
	std::cout << __PRETTY_FUNCTION__ << "\t" << __LINE__ << std::endl;
	while(m_is_activated){
		lct_log_shp_type log_shp;
		if(lct_error_code_t::lct_error_code_successful == m_log_queue.dequeue(log_shp)){
			std::cout << log_shp->c_str() << std::endl;
		}
	}
	std::cout << __PRETTY_FUNCTION__ << "\t" << __LINE__ << std::endl;
}

void lct_log_helper_t::close(){
	m_is_activated = false;
}


