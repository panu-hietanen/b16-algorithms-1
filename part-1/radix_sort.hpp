#ifndef __radix_sort__
#define __radix_sort__

#include <algorithm>
#include <limits>
#include <vector>
#include <cmath>

#include "utils.hpp"

template <typename I>
static constexpr int num_digits_v =
    std::numeric_limits<typename I::value_type>::digits;

template <typename T>
int getDigit(T number, int place)
{
    return (number / static_cast<int>(std::pow(10, place))) % 10;
}

template <typename I>
void radix_sort_decimal(const I &begin, const I &end,
                int digit = num_digits_v<I>)
{
    // WRITE YOUR CODE HERE
    std::vector<std::vector<typename I::value_type>> buckets(10);

    for (int k=0; k<digit; ++k)
    {
        for (I n = begin; n != end; ++n)
        {
            int b_digit = getDigit(*n, k);
            buckets[b_digit].push_back(*n);
        }
        I it = begin;
        for (int i = 0; i<10; ++i)
        {
            for (auto& number : buckets[i])
            {
                *it = number;
                ++it;
            }
            buckets[i].clear();
        }
    }


}


template <typename I>
void radix_sort(const I &begin, const I &end, int digit = num_digits_v<I>)
{
    std::vector<std::vector<typename I::value_type>> bins(2);
    
    for (int k = 0; k<digit; ++k)
    {
        for (I n = begin; n != end; ++n)
        {
            int bin = (*n / static_cast<int>(std::pow(2, k))) % 2;
            bins[bin].push_back(*n);
        }

        I iter = begin;
        for (int i = 0; i < 2; ++i)
        {
            for (auto& n : bins[i])
            {
                *iter = n;
                ++iter;
            }
            bins[i].clear();
        }
    }

}

#endif // __radix_sort__