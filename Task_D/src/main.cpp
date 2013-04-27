//
//  main.cpp
//  Radixsort
//
//  Created by Loc Nguyen on 19.04.12.
//  Copyright (c) 2012 Universität Zürich. All rights reserved.
//
//  Authored by Remo Koch
//  Public repository at https://github.com/rkoch/uzh-inf02b-a5
//

#include <cstdlib>		// Needed for rand()
#include <ctime>
#include <string>

#include "selection_sort.h"
#include "merge_sort.h"
#include "bucket_sort.h"
#include "radix_sort.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::flush;

#define LENGTH 50000

void printSortResults(const string pAlgorithm, clock_t &pStart, clock_t &pEnd, vector<int> &pSortedList);
void printList(vector<int> &pList);

int main(int argc, const char *argv[]) {
	srand(getpid());

	// Fill lists - for more accurate performance measuring there are
	// 4 lists containing the same entries in the same order.
	vector<int> list_selection;
	for (int i = 0; i < LENGTH; i++) {
		int rnumber = rand() % 1000;
		list_selection.push_back(rnumber);
	}
	vector<int> list_merge(list_selection);
	vector<int> list_bucket(list_selection);
	vector<int> list_radix(list_selection);

	cout << "List before sorting: " << endl;
	printList(list_selection);

	// Selection sort
	clock_t cBegin = clock();
	selection_sort(list_selection);
	clock_t cEnd = clock();
	printSortResults("Selection Sort", cBegin, cEnd, list_selection);

	// Merge sort
	cBegin = clock();
	merge_sort(list_merge);
	cEnd = clock();
	printSortResults("Merge Sort", cBegin, cEnd, list_merge);

	// Bucket sort
	cBegin = clock();
	bucket_sort(list_bucket);
	cEnd = clock();
	printSortResults("Bucket Sort", cBegin, cEnd, list_bucket);

	// Radix sort
	cBegin = clock();
	radix_sort(list_radix);
	cEnd = clock();
	printSortResults("Radix Sort", cBegin, cEnd, list_radix);

	// Validate algorithm results
	cout << endl;
	cout << "---------------------" << endl;
	bool valSelection = true;
	bool valMerge = true;
	bool valBucket = true;
	bool valRadix = true;

	for (int i = 1; i < LENGTH; i++) {
		if (list_selection[i - 1] > list_selection[i]) {
			valSelection = false;
		}
		if (list_merge[i - 1] > list_merge[i]) {
			valMerge = false;
		}
		if (list_bucket[i - 1] > list_bucket[i]) {
			valBucket = false;
		}
		if (list_radix[i - 1] > list_radix[i]) {
			valRadix = false;
		}
		if (!(valSelection & valMerge & valBucket & valRadix)) {
			break;
		}
	}

	cout << "Selection Sort did " << (valSelection ? "" : "not ") << "return correct results." << (valSelection ? " You're done with that one." : "") << endl;
	cout << "Merge Sort did " << (valMerge ? "" : "not ") << "return correct results." << (valMerge ? " You're done with that one." : "") << endl;
	cout << "Bucket Sort did " << (valBucket ? "" : "not ") << "return correct results." << (valBucket ? " You're done with that one." : "") << endl;
	cout << "Radix Sort did " << (valRadix ? "" : "not ") << "return correct results." << (valRadix ? " You're done with that one." : "") << endl;

	return 0;
}

void printSortResults(const string pAlgorithm, clock_t &pStart, clock_t &pEnd, vector<int> &pSortedList) {
	cout << endl;
	cout << "---------------------" << endl;
	cout << pAlgorithm << " took " << 1000.0 * double(pEnd - pStart) / CLOCKS_PER_SEC << "ms" << endl;

	// Print sorted list
	cout << "List after " << pAlgorithm << ": " << endl;
	printList(pSortedList);

}

void printList(vector<int> &pList) {
//	for (int i = 0; i < LENGTH; i++) {
//		cout << pList[i] << " " << flush;
//	}
//	cout << endl;
}
