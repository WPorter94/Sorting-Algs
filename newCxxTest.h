
//copyright 2021

#ifndef SORTING_NEWCXXTEST_H
#define SORTING_NEWCXXTEST_H



#include <cxxtest/TestSuite.h>
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

using std::cout;
using std::endl;
using std::vector;

typedef void (*psort2)(vector<int>::iterator, vector<int>::iterator,
	int&, int&);

psort2 sorts2[] = {
		KW::selection_sort<vector<int>::iterator>,
		KW::bubble_sort<vector<int>::iterator>,
		KW::insertion_sort<vector<int>::iterator>,
		KW::shell_sort<vector<int>::iterator>,
		KW::merge_sort<vector<int>::iterator>,
		KW::heap_sort<vector<int>::iterator>,
		KW::quick_sort<vector<int>::iterator>
};

std::string sort_names2[] = {
		"selection_sort",
		"bubble_sort",
		"insertion_sort",
		"shell_sort",
		"merge_sort",
		"heap_sort",
		"quick_sort"
};

class newCxxTest : public CxxTest::TestSuite {
public:

	void testAllSorts() {
		const int num_sorts = 7;
		int tot_compares[7];
		int tot_exchanges[7];
		const int num_items = 1000;

		vector<int> aVec;
		Random rand(100);
		cout << endl << num_items << endl;

		for (int i = 0; i < num_items; i++) {
			aVec.push_back(rand.next_int(num_items / 5));
		}
		vector<int> copyVec = aVec;

		cout << "Sort\tCompares\tExchanges\n";
		for (int i = 0; i < num_sorts; i++) {
			tot_compares[i] = 0;
			tot_exchanges[i] = 0;
			copyVec = aVec;
			sorts2[i](copyVec.begin(), copyVec.end(),
				tot_compares[i], tot_exchanges[i]);
			cout << sort_names2[i] << '\t'
				<< tot_compares[i] << '\t'
				<< tot_exchanges[i] << '\n';


			//TS_ASSERT_EQUALS(tot_compares[i], compares_results[i]);
			//TS_ASSERT_EQUALS(tot_exchanges[i], exchanges_results[i]);
		}
	}

	void testShellGap2() {
		int testSorts(int[], int[], int, int);
		const int num_sorts = 7;
		int tot_compares[7];
		int tot_exchanges[7];
		const int num_items = 1000;

		vector<int> aVec;
		Random rand;
		cout << endl << num_items << endl;
		for (int i = 0; i < num_items; i++) {
			aVec.push_back(rand.next_int(num_items / 5));
		}
		vector<int> copyVec = aVec;

		cout << "Sort\tCompares\tExchanges\n";
		for (int i = 0; i < num_sorts; i++) {
			tot_compares[i] = 0;
			tot_exchanges[i] = 0;
			copyVec = aVec;
			sorts2[i](copyVec.begin(), copyVec.end(),
				tot_compares[i], tot_exchanges[i]);
			cout << sort_names2[i] << '\t'
				<< tot_compares[i] << '\t'
				<< tot_exchanges[i] << '\n';
			Random random;


			//TS_ASSERT_EQUALS(tot_compares[i], compares_results[i]);
			//TS_ASSERT_EQUALS(tot_exchanges[i], exchanges_results[i]);
			testSorts(tot_compares, tot_exchanges, num_sorts, num_items);
		}
	}
	void testSelectionSort() {

		const int num_sorts = 1;
		int tot_compares[1];
		int tot_exchanges[1];
		const int num_items = 50;

		vector<int> aVec;
		aVec.push_back(190);
		aVec.push_back(184);
		aVec.push_back(105);
		aVec.push_back(42);
		aVec.push_back(101);
		aVec.push_back(80);
		aVec.push_back(100);
		aVec.push_back(14);
		aVec.push_back(86);
		aVec.push_back(86);
		aVec.push_back(159);
		aVec.push_back(88);
		aVec.push_back(73);
		aVec.push_back(25);
		cout << "Selection sort test" << endl;
		cout << "Sort\tCompares\tExchanges\n";
		sorts2[0](aVec.begin(), aVec.end(), tot_compares[0], tot_exchanges[0]);
		cout << "Selection Sort" << '\t' << tot_compares[0] << '\t' << tot_exchanges[0] << endl;
		TS_ASSERT_EQUALS(tot_compares[0], 91);
		TS_ASSERT_EQUALS(tot_exchanges[0], 12);

	}
	void testBubbleSort() {

		const int num_sorts = 1;
		int tot_compares[1];
		int tot_exchanges[1];
		const int num_items = 50;

		vector<int> aVec;
		aVec.push_back(190);
		aVec.push_back(184);
		aVec.push_back(105);
		aVec.push_back(42);
		aVec.push_back(101);
		aVec.push_back(80);
		aVec.push_back(100);
		aVec.push_back(14);
		aVec.push_back(86);
		aVec.push_back(86);
		aVec.push_back(159);
		aVec.push_back(88);
		aVec.push_back(73);
		aVec.push_back(25);

		cout << "Bubble sort test" << endl;
		cout << "Sort\tCompares\tExchanges\n";
		sorts2[1](aVec.begin(), aVec.end(), tot_compares[0], tot_exchanges[0]);
		cout << "Bubble Sort" << '\t' << tot_compares[0] << '\t' << tot_exchanges[0] << endl;
		TS_ASSERT_EQUALS(tot_compares[0], 91);
		TS_ASSERT_EQUALS(tot_exchanges[0], 64);

	}
	void testInsertionSort() {

		const int num_sorts = 1;
		int tot_compares[1];
		int tot_exchanges[1];
		const int num_items = 50;

		vector<int> aVec;
		aVec.push_back(190);
		aVec.push_back(184);
		aVec.push_back(105);
		aVec.push_back(42);
		aVec.push_back(101);
		aVec.push_back(80);
		aVec.push_back(100);
		aVec.push_back(14);
		aVec.push_back(86);
		aVec.push_back(86);
		aVec.push_back(159);
		aVec.push_back(88);
		aVec.push_back(73);
		aVec.push_back(25);
		cout << "Insertion sort test" << endl;
		cout << "Sort\tCompares\tExchanges\n";
		sorts2[2](aVec.begin(), aVec.end(), tot_compares[0], tot_exchanges[0]);
		cout << "Insertion Sort" << '\t' << tot_compares[0] << '\t' << tot_exchanges[0] << endl;
		TS_ASSERT_EQUALS(tot_compares[0], 77);
		TS_ASSERT_EQUALS(tot_exchanges[0], 64);

	}
	void testShellSort() {

		const int num_sorts = 1;
		int tot_compares[1];
		int tot_exchanges[1];
		const int num_items = 50;

		vector<int> aVec;
		aVec.push_back(190);
		aVec.push_back(184);
		aVec.push_back(105);
		aVec.push_back(42);
		aVec.push_back(101);
		aVec.push_back(80);
		aVec.push_back(100);
		aVec.push_back(14);
		aVec.push_back(86);
		aVec.push_back(86);
		aVec.push_back(159);
		aVec.push_back(88);
		aVec.push_back(73);
		aVec.push_back(25);
		cout << "Shell sort test" << endl;
		cout << "Sort\tCompares\tExchanges\n";
		sorts2[3](aVec.begin(), aVec.end(), tot_compares[0], tot_exchanges[0]);
		cout << "Shell Sort" << '\t' << tot_compares[0] << '\t' << tot_exchanges[0] << endl;
		TS_ASSERT_EQUALS(tot_compares[0], 28);
		TS_ASSERT_EQUALS(tot_exchanges[0], 109);

	}
	void testMergeSort() {

		const int num_sorts = 1;
		int tot_compares[1];
		int tot_exchanges[1];
		const int num_items = 50;

		vector<int> aVec;
		aVec.push_back(190);
		aVec.push_back(184);
		aVec.push_back(105);
		aVec.push_back(42);
		aVec.push_back(101);
		aVec.push_back(80);
		aVec.push_back(100);
		aVec.push_back(14);
		aVec.push_back(86);
		aVec.push_back(86);
		aVec.push_back(159);
		aVec.push_back(88);
		aVec.push_back(73);
		aVec.push_back(25);
		cout << "Merge sort test" << endl;
		cout << "Sort\tCompares\tExchanges\n";
		sorts2[4](aVec.begin(), aVec.end(), tot_compares[0], tot_exchanges[0]);
		cout << "Merger Sort" << '\t' << tot_compares[0] << '\t' << tot_exchanges[0] << endl;
		TS_ASSERT_EQUALS(tot_compares[0], 6545974);
		TS_ASSERT_EQUALS(tot_exchanges[0], 54);

	}
	void testHeapSort() {

		const int num_sorts = 1;
		int tot_compares[1];
		int tot_exchanges[1];
		const int num_items = 50;

		vector<int> aVec;
		aVec.push_back(190);
		aVec.push_back(184);
		aVec.push_back(105);
		aVec.push_back(42);
		aVec.push_back(101);
		aVec.push_back(80);
		aVec.push_back(100);
		aVec.push_back(14);
		aVec.push_back(86);
		aVec.push_back(86);
		aVec.push_back(159);
		aVec.push_back(88);
		aVec.push_back(73);
		aVec.push_back(25);
		cout << "Heap sort test" << endl;
		cout << "Sort\tCompares\tExchanges\n";
		sorts2[5](aVec.begin(), aVec.end(), tot_compares[0], tot_exchanges[0]);
		cout << "Heap Sort" << '\t' << tot_compares[0] << '\t' << tot_exchanges[0] << endl;
		TS_ASSERT_EQUALS(tot_compares[0], 50);
		TS_ASSERT_EQUALS(tot_exchanges[0], 40);

	}
	void testQuickSort() {

		const int num_sorts = 1;
		int tot_compares[1];
		int tot_exchanges[1];
		const int num_items = 50;

		vector<int> aVec;
		aVec.push_back(190);
		aVec.push_back(184);
		aVec.push_back(105);
		aVec.push_back(42);
		aVec.push_back(101);
		aVec.push_back(80);
		aVec.push_back(100);
		aVec.push_back(14);
		aVec.push_back(86);
		aVec.push_back(86);
		aVec.push_back(159);
		aVec.push_back(88);
		aVec.push_back(73);
		aVec.push_back(25);
		cout << "Quick sort test" << endl;
		cout << "Sort\tCompares\tExchanges\n";
		sorts2[6](aVec.begin(), aVec.end(), tot_compares[0], tot_exchanges[0]);
		cout << "Quick Sort" << '\t' << tot_compares[0] << '\t' << tot_exchanges[0] << endl;
		TS_ASSERT_EQUALS(tot_compares[0], 6545968);
		TS_ASSERT_EQUALS(tot_exchanges[0], 14);

	}

};



#endif //SORTING_NEWCXXTEST_H
