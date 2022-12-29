#ifndef UTIL_H
#define UTIL_H
// https://en.cppreference.com/w/cpp/chrono/time_point
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
// using namespace std;

void slow_motion()
{
    static int a[] {1,2,3,4,5,6,7,8,9,10,11,12};
    while (std::ranges::next_permutation(a).found)
    { } // generates 12! permutations
}

void get_time()
{
    using namespace std::literals;
    const std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    const std::time_t t_c = std::chrono::system_clock::to_time_t(now - 24h);
    std::cout<<std::put_time(std::localtime(&t_c), "%Y/%m/%d %T\n")<< std::flush;
}

#endif // UTIL_H