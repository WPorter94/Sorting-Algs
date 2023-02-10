
//copyright 2021

#ifndef SORTING_SHELL_SORT_H
#define SORTING_SHELL_SORT_H

#include <algorithm>

namespace KW {


    template<typename RI>
    void shell_sort(RI first, RI last, int& tot_compare, int& tot_exchange) {
        tot_compare = 0;
        tot_exchange = 0;
        int gap = (last - first) / 2;
        while (gap > 0) {
            for (RI next_pos = first + gap; next_pos != last; ++next_pos) {
                typename std::iterator_traits<RI>::value_type next_val = *next_pos;
                while ((next_pos > first + gap - 1) && (next_val < *(next_pos - gap))) {
                    *next_pos = *(next_pos - gap);
                    next_pos -= gap;
                    ++tot_compare;
                }
                *next_pos = next_val;
                ++tot_exchange;
            }
            if (gap == 2) {
                gap = 1;
            }
            else
            {
                gap = int(gap / 2.2);
            }
        }

    }
} // End namespace KW
#endif //SORTING_SHELL_SORT_H
