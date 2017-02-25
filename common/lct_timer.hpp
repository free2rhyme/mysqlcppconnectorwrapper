/*
 * lct_timer.hpp
 *
 *  Created on: Sep 27, 2016
 *      Author: Ralph.Liu
 *       Email: wlc2rhyme@gmail.com
 */

#ifndef SRC_COMMON_LCT_TIMER_HPP_
#define SRC_COMMON_LCT_TIMER_HPP_

#include <functional>
#include <chrono>
#include <future>

class lct_timer_t{
public:
    template <class callable,  class... arguments>
    lct_timer_t(int duration_milliseconds, bool is_async, bool is_repeat, callable&& func, arguments&&... vargs){
        std::function<typename std::result_of<callable(arguments...)>::type()> task(std::bind(std::forward<callable>(func), std::forward<arguments>(vargs)...));

        const std::chrono::milliseconds durn(duration_milliseconds);
        if(is_async){
            std::thread([duration_milliseconds, task, durn, is_repeat]() {
            	std::this_thread::sleep_for(durn);
                task();

                while(is_repeat){
                	std::this_thread::sleep_for(durn);
                    task();
                }
            }).detach();


        } else {
            std::this_thread::sleep_for(durn);
            task();
            while(is_repeat){
                std::this_thread::sleep_for(durn);
                task();
            }
        }
    }
};

#endif /* SRC_COMMON_LCT_TIMER_HPP_ */
