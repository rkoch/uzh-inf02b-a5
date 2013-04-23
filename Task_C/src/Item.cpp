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
#include "Item.h"

Item::Item(int key_, std::string name_) {
	key = key_;
	name = name_;
}

std::string Item::getName() {
	return name;
}

int Item::getKey() {
	return key;
}
