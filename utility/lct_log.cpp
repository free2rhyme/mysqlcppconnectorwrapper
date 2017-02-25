/*
 * lct_log.cpp
 *
 *  Created on: Nov 4, 2016
 *      Author: Ralph.Liu
 *       Email: wlc2rhyme@gmail.com
 */

#include "lct_log.h"
#include "lct_log_id.h"

lct_log::lct_log(const std::string& str):m_log_id(lct_log_id_t::instance().get_next_id()), m_log_str(str){
}

lct_log::~lct_log(){
}

lct_log::lct_log(const lct_log& that):m_log_id(that.m_log_id),m_log_str(that.m_log_str) {

}
lct_log& lct_log::operator=(const lct_log& that){
	if(&that == this){
		return *this;
	}
	m_log_id = that.m_log_id;
	m_log_str = that.m_log_str;
	return *this;
}
lct_log::lct_log(lct_log&& that):m_log_id(that.m_log_id){
	m_log_str = std::move(that.m_log_str);
}
lct_log& lct_log::operator=(lct_log&& that){
	if(&that == this){
		return *this;
	}
	m_log_id = that.m_log_id;
	m_log_str = std::move(that.m_log_str);
	return *this;
}

const char* lct_log::c_str() const{
	return m_log_str.c_str();
}
