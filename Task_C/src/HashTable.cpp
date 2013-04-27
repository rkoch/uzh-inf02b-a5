/*
 *  University of Zurich
 *  Department of Informatics
 *  Visualization and Multimedia Laboratory
 *
 *  Algorithms and Data structures
 *  Author: Genc Mazlami
 *
 *  Authored by Remo Koch
 *  Public repository at https://github.com/rkoch/uzh-inf02b-a5
 */

#include <iostream>
#include <cmath>
#include "HashTable.h"

HashTable::HashTable() {
	table = new Item*[TABLE_SIZE];

	// Using MAD compression map, therefore we need factors a and b
	factor_a = 7;
	factor_b = 13;
}

int HashTable::hashfunction(int key_) {
	int index = (factor_a * key_ + factor_b) % TABLE_SIZE;          // compute the hash of the key using MAD compression (see slides)
	return index;
}

void HashTable::put(Item* item) {
	int h = hashfunction(item->getKey());

	// linear probing
	while ((h < TABLE_SIZE) && (table[h] != NULL)) {
		h++;
	}

	// If overflow was detected
	if (h >= TABLE_SIZE) {
		std::cerr << "Error: HashTable Overflow! Could not save item (" << item->getKey() << ", " << item->getName() << ")." << std::endl;
		return;
	}

	table[h] = item;
}

Item* HashTable::get(int key_) {
	int h = hashfunction(key_);

	Item* ret = table[h++];
	while ((h < TABLE_SIZE) && (ret != NULL) && (ret->getKey() != key_)) {
		ret = table[h++];
	}

	// If overflow was detected
	if ((h >= TABLE_SIZE) && (ret != NULL) && (ret->getKey() != key_)) {
		ret = NULL;
	}

	return ret;
}

void HashTable::putQuadratic(Item* item) {
	int h;
	int j = 0;

	while (j < TABLE_SIZE) {
		h = hashfunction(item->getKey() + j * j);
		if (table[h] == NULL) {
			table[h] = item;
			return;
		}
		j++;
	}

	std::cerr << "Error: HashTable Overflow! Could not save item (" << item->getKey() << ", " << item->getName() << ")." << std::endl;
}

Item* HashTable::getQuadratic(int key_) {
	int h;
	int j = 0;

	Item* ret = NULL;
	while (j < TABLE_SIZE) {
		h = hashfunction(key_ + j * j);

		if ((table[h] == NULL) || (table[h]->getKey() == key_)) {
			return table[h];
		}

		j++;
	}

	return ret;
}

void HashTable::printContent() {
	std::cout << "-----------------------------" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (table[i] == NULL) {
			std::cout << i << "\t | \t" << "NULL" << std::endl;
			std::cout << "-----------------------------" << std::endl;
		} else {
			std::cout << i << "\t | \t" << table[i]->getName();
			std::cout << std::endl;											// Workaround due to a bug in Eclipse/OS X
			std::cout << "-----------------------------" << std::endl;
		}
	}
	std::cout << "-----------------------------" << std::endl;
}
