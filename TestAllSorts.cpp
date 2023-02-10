
//copyright 2021


#include <iostream>
#include <iterator>
#include <vector>
#include "Random.h"
#include "Selection_Sort.h"
#include "Bubble_Sort.h"
#include "Insertion_Sort.h"
#include "Shell_Sort.h"
#include "Merge_Sort.h"
#include "Heap_Sort.h"
#include "Quick_Sort.h"

int testSorts(int[], int[], int, int);

using namespace std;

typedef void (*psort)(vector<int>::iterator, vector<int>::iterator,
                      int&, int&);

psort sorts[] = {KW::selection_sort<vector<int>::iterator>,
                 KW::bubble_sort<vector<int>::iterator>,
                 KW::insertion_sort<vector<int>::iterator>,
                 KW::shell_sort<vector<int>::iterator>,
                 KW::merge_sort<vector<int>::iterator>,
                 KW::heap_sort<vector<int>::iterator>,
                 KW::quick_sort<vector<int>::iterator>
};

std::string sort_names[] = {"selection_sort",
                            "bubble_sort",
                            "insertion_sort",
                            "shell_sort",
                            "merge_sort",
                            "heap_sort",
                            "quick_sort"
};



int testSorts(int tot_compares[], int tot_exchanges[], int num_sorts, int num_items) {

    vector<int> aVec;
    Random rand(100);
    cout << endl << num_items << endl;
    // Fill vector aVec with random numbers.
    for (int i = 0; i < num_items; i++) {
        aVec.push_back(rand.next_int(num_items / 5));
    }
    vector<int> copyVec = aVec; // A copy of aVec.

    // Sort and verify using KW sorting functions.
    cout << "Sort\tCompares\tExchanges\n";
    for (int i = 0; i < num_sorts; i++) {
        tot_compares[i] = 0;
        tot_exchanges[i] = 0;
        copyVec = aVec;

        sorts[i](copyVec.begin(), copyVec.end(),
            tot_compares[i], tot_exchanges[i]);
        cout << sort_names[i] << '\t'
            << tot_compares[i] << '\t'
            << tot_exchanges[i] << '\n';
    }
    return 0;

};
