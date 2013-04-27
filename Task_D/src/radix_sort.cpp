//
//  radix_sort.cpp
//  radixsort
//
//  Created by Loc Nguyen on 19.04.12.
//  Copyright (c) 2012 Universität Zürich. All rights reserved.
//
//  Authored by Remo Koch
//  Public repository at https://github.com/rkoch/uzh-inf02b-a5
//

#include <algorithm>
#include <sstream>
#include <map>
#include <math.h>

#include "radix_sort.h"

using std::vector;

void radix_sort(std::vector<int> &input_list) {
	std::map<int, std::vector<int> > buckets;

	// Find length of largest number
	int max = 0;
	for (unsigned i = 0; i < input_list.size(); i++) {
		max = std::max(max, input_list[i]);
	}
	// Convert number to string to find length
	std::stringstream ss;
	ss << max;
	unsigned maxLen = ss.str().size();

	for (unsigned i = 0; i < maxLen; i++) {
		// Partition
		for (unsigned j = 0; j < input_list.size(); j++) {
			int key = (input_list[j] / (int) pow(10.0, i)) % 10;
			buckets[key].push_back(input_list[j]);
		}

		// Collect
		input_list.clear();
		for (int j = 0; j < 10; j++) {
			for (unsigned k = 0; k < buckets[j].size(); k++) {
				input_list.push_back(buckets[j][k]);
			}
			buckets[j].clear();
		}
	}
}
