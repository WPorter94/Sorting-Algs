
//copyright 2021

#ifndef SORTING_QUICK_SORT_H
#define SORTING_QUICK_SORT_H


#include <algorithm>

namespace KW {



    template<typename RI>
    RI partition(RI first, RI last  , int& tot_compare, int& tot_exchange ) {
// Start up and down at either end of the sequence.
// The first table element is the pivot value.
        RI up = first + 1;
        RI down = last - 1;
        do {
/* Invariant:
All items in table[first] through table[up - 1] <= table[first]
All items in table[down + 1] through table[last - 1] > table[first]
*/          ++tot_compare;
            while ((up != last - 1) && !(*first < *up)) {
                ++up;
            }
// Assert: up equals last-1 or table[up] > table[first].
            ++tot_compare;
            while (*first < *down) {
                --down;
            }
// Assert: down equals first or table[down] <= table[first].
            ++tot_compare;
            if (up < down) { // if up is to the left of down,
// Exchange table[up] and table[down].
                std::iter_swap(up, down);
                tot_exchange++;
            }
            ++tot_compare;
        } while (up < down); // Repeat while up is left of down.
// Exchange table[first] and table[down] thus putting the
// pivot value where it belongs.
// Return position of pivot.
        std::iter_swap(first, down);
        tot_exchange++;
        return down;
    }


    /** Sort data in the specified sequence using selection sort.
        @param RI An iterator that meets the
                  random-access iterator requirements
        @param first An iterator that references the first element
                     of the sequence to be sorted
        @param last An iterator that references one past the
                    end of the sequence to be sorted
    */
    template<typename RI>
    void quick_sort(RI first, RI last , int& tot_compare, int& tot_exchange) {
        if (last - first > 1) { // There is data to be sorted.
// Partition the table.
            RI pivot = partition(first, last , tot_compare, tot_exchange);
// Sort the left half.
            KW::quick_sort(first, pivot ,tot_compare, tot_exchange );
// Sort the right half.
            KW::quick_sort(pivot + 1, last, tot_compare, tot_exchange);
        }
    }
} // End namespace KW
#endif //SORTING_QUICK_SORT_H
