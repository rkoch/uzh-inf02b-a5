//
//  Created by Rafael Ballester on 10.04.13.
//  Copyright (c) 2013 Universität Zürich. All rights reserved.
//
//  Authored by Remo Koch
//  Public repository at https://github.com/rkoch/uzh-inf02b-a5
//

#include <iostream>
#include "bucket_sort.h"

#define RANGE 1000

void bucket_sort(std::vector<int> &numbers) {
	// Create buckets and zero them
	int buckets[RANGE];
	for (int i = 0; i < RANGE; i++) {
		buckets[i] = 0;
	}

	// Fill vector to buckets
	for (int i = 0; i < numbers.size(); i++) {
		buckets[numbers[i]]++;
	}

	// Clear vector
	numbers.clear();

	// Refill vector
	for (int i = 0; i < RANGE; i++) {
		for (int j = 0; j < buckets[i]; j++) {
			numbers.push_back(i);
		}
	}
}
