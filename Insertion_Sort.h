
//copyright 2021

#ifndef SORTING_INSERTION_SORT_H
#define SORTING_INSERTION_SORT_H

#include <algorithm>

namespace KW {


    template<typename RI>
    void insertion_sort(RI first, RI last, int& tot_compare, int& tot_exchange) {
        tot_compare = 0;
        tot_exchange = 0;
        for (RI next_pos = first +1; next_pos != last; ++next_pos) {
            ++tot_compare;
            while (next_pos != first && *next_pos < *(next_pos - 1)) {
                std::iter_swap(next_pos, next_pos - 1);
                --next_pos;
                ++tot_exchange;
            }
        }

    }
} // End namespace KW
#endif //SORTING_INSERTION_SORT_H
