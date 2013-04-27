//
//  Authored by Remo Koch
//  Public repository at https://github.com/rkoch/uzh-inf02b-a5
//

#include <iostream>
#include "merge_sort.h"

// Split a vector into two parts and recursively call merge() on each of them
void merge_sort(std::vector<int> &numbers) {
	if (numbers.size() > 1) {
		// Split vector in half
		std::size_t const half = numbers.size() / 2;
		std::vector<int> left(numbers.begin(), numbers.begin() + half);
		std::vector<int> right(numbers.begin() + half, numbers.end());

		// Sort each one
		merge_sort(left);
		merge_sort(right);

		// Merge vectors again
		merge(left, right, numbers);
	}
}

// Merge two sorted lists (numbers1 and numbers2) into one sorted list (numbers)
void merge(std::vector<int> &numbers1, std::vector<int> &numbers2, std::vector<int> &numbers) {
	unsigned leftIdx = 0;
	unsigned rightIdx = 0;

	// Empty resulting array for easy use of push_back()
	numbers.clear();

	// As long as both lists contain elements
	while ((leftIdx < numbers1.size()) && (rightIdx < numbers2.size())) {
		if (numbers1[leftIdx] <= numbers2[rightIdx]) {
			numbers.push_back(numbers1[leftIdx++]);
		} else {
			numbers.push_back(numbers2[rightIdx++]);
		}
	}
	// Only left list contains elements
	while (leftIdx < numbers1.size()) {
		numbers.push_back(numbers1[leftIdx++]);
	}
	// Only right list contains elements
	while (rightIdx < numbers2.size()) {
		numbers.push_back(numbers2[rightIdx++]);
	}
}
