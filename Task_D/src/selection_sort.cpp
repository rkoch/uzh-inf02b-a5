//
//  Created by Rafael Ballester on 10.04.13.
//  Copyright (c) 2013 Universität Zürich. All rights reserved.
//
//  Authored by Remo Koch
//  Public repository at https://github.com/rkoch/uzh-inf02b-a5
//

#include <iostream>
#include <algorithm>

#include "selection_sort.h"

void selection_sort(std::vector<int> &numbers) {
	for (unsigned i = 0; i < numbers.size(); i++) {
		int min = numbers[i];
		unsigned minIdx = i;
		for (unsigned j = i + 1; j < numbers.size(); j++) {
			if (numbers[j] < min) {
				min = numbers[j];
				minIdx = j;
			}
		}
		if (minIdx != i) {
			std::swap(numbers[minIdx], numbers[i]);
		}
	}
}
