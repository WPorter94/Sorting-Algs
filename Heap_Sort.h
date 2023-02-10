
//copyright 2021

#ifndef SORTING_HEAP_SORT_H
#define SORTING_HEAP_SORT_H


#include <algorithm>

namespace KW {


    template<typename RI>
    void heap_sort(RI first, RI last, int& tot_compare, int& tot_exchange) {
        tot_compare = 0;
        tot_exchange = 0;

        int n = 1;
        while (n < (last - first)) {
            ++tot_compare;
            ++n;
            RI child = first + n - 1;
            RI parent = first + (child - first - 1) / 2;
            while (parent >= first && *parent < *child) {
                std::iter_swap(parent, child);
                ++tot_exchange;
                child = parent;
                parent = first + (child - first - 1) / 2;
            }
        }
        RI m = last;
        while (m != first) {
            ++tot_compare;
            --m;
            std::iter_swap(first, m);
            tot_exchange++;
            RI parent = first;
            while (true) {
                RI left_child = first + 2 * (parent - first) + 1;
                if (left_child >= m) {
                    break;
                }
                RI right_child = left_child + 1;
                RI max_child = left_child;
                if (right_child < m && *left_child < *right_child) {
                    max_child = right_child;
                }
                tot_compare++;
                if (*parent < *max_child) {
                    std::iter_swap(parent, max_child);
                    tot_exchange++;
                    parent = max_child;

                }
                else
                {
                    break;
                }
            }
        }
    }
} // End namespace KW
#endif //SORTING_HEAP_SORT_H
