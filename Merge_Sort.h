
//copyright 2021

#ifndef SORTING_MERGE_SORT_H
#define SORTING_MERGE_SORT_H

#include <algorithm>
#include <vector>
namespace KW {

    template<typename RI>
    void merge(RI left, RI end_left,
               RI right, RI end_right,
               RI out,int& tot_compare, int& tot_exchange) {
        // while there is data in both input sequences
        while (left != end_left && right != end_right) {
            // find the smaller and
            // insert it into the output sequence
            ++tot_compare;
            if (*left < *right) {
                *out++ = *left++;
                tot_exchange++;
            }
            else
            {
                ++tot_exchange;
                *out++ = *right++;
            }
        }

        // Assert: one of the sequences has more items to copy.
        // Copy remaining input from left sequence into ouput
        while (left != end_left) {
            *out++ = *left++;
            tot_exchange++;
        }

        //copy remaining input from right sequence into output
        while (right != end_right) {
            *out++ = *right++;
            tot_exchange++;
        }
    }
    template<typename RI>
    void merge_sort(RI first, RI last,int& tot_compare, int& tot_exchange) {
        tot_compare++;
        if (last - first > 1) {
            // split table into two new half tables
            typedef typename std::iterator_traits<RI>::value_type value_type;
            RI middle = first + (last - first) / 2;
            std::vector<value_type> left_table(first, middle);
            std::vector<value_type> right_table(middle, last);

            // sort the halves
            KW::merge_sort(left_table.begin(), left_table.end(),tot_compare, tot_exchange);
            KW::merge_sort(right_table.begin(), right_table.end(),tot_compare, tot_exchange);

            // merge the halves back into the original table.
            merge(left_table.begin(), left_table.end(),
                  right_table.begin(), right_table.end(),
                  first,tot_compare, tot_exchange);
        }
    }
} // End namespace KW
#endif //SORTING_MERGE_SORT_H
