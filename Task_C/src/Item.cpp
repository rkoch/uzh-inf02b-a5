/*
 *  University of Zurich
 *  Department of Informatics
 *  Visualization and Multimedia Laboratory
 *
 *  Algorithms and Data structures
 *  Author: Genc Mazlami
 */

#include <iostream>
#include "Item.h"

Item::Item(int key_, std::string name_){
    key = key_;
    name = name_;
}

std::string Item::getName(){
    return name;
}

int Item::getKey(){
    return key;
}
