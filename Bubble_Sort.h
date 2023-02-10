
//copyright 2021

#ifndef SORTING_BUBBLE_SORT_H
#define SORTING_BUBBLE_SORT_H

#include <algorithm>

namespace KW {


    template<typename RI>
    void bubble_sort(RI first, RI last, int& tot_compare, int& tot_exchange) {
        tot_compare = 0;
        tot_exchange = 0;
        int pass = 1;
        bool exchanges;
        do {
            exchanges = false;
            for (RI fill = first; fill != last - pass; ++fill) {
                RI pos_min = fill + 1;
                ++tot_compare;
                if (*pos_min < *fill) {

                    ++tot_exchange;
                    std::iter_swap(pos_min, fill);
                    exchanges = true;
                }
            }
            pass++;
        } while (exchanges);

    }
} // End namespace KW
#endif //SORTING_BUBBLE_SORT_H
