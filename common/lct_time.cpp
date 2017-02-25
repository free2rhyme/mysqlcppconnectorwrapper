/*
 * lct_time.cpp
 *
 *  Created on: Sep 28, 2016
 *      Author: Ralph.Liu
 *       Email: wlc2rhyme@gmail.com
 */

#include "lct_time.h"
#include <chrono>

/**
 *
template <typename Duration>
void print_time(tm t, Duration fraction) {
    using namespace std::chrono;
    std::printf("[%04u-%02u-%02u %02u:%02u:%02u.%03u]\n", t.tm_year + 1900,
                t.tm_mon + 1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec,
                static_cast<unsigned>(fraction / milliseconds(1)));

    // VS2013's library has a bug which may require you to replace
    // "fraction / milliseconds(1)" with
    // "duration_cast<milliseconds>(fraction).count()"
}

int main() {
    using namespace std;
    using namespace std::chrono;

    system_clock::time_point now = system_clock::now();
    system_clock::duration tp = now.time_since_epoch();

    tp -= duration_cast<seconds>(tp);

    time_t tt = system_clock::to_time_t(now);

    print_time(*gmtime(&tt), tp);
    print_time(*localtime(&tt), tp);
}
 */

const std::string get_current_system_time(){
	std::chrono::system_clock::time_point now  = std::chrono::system_clock::now();
	std::chrono::system_clock::duration   durn = now.time_since_epoch();
	durn -= std::chrono::duration_cast<std::chrono::seconds>(durn);

	auto tt = std::chrono::system_clock::to_time_t(now);
	struct tm* ptm = localtime(&tt);
	char date[60] = {0};
	sprintf(date, "%d-%02d-%02d	%02d:%02d:%02d:%02d",
		(int)ptm->tm_year + 1900,(int)ptm->tm_mon + 1,(int)ptm->tm_mday,
		(int)ptm->tm_hour,(int)ptm->tm_min,(int)ptm->tm_sec,static_cast<unsigned>(durn / std::chrono::milliseconds(1)));

	return std::string(date);
}
