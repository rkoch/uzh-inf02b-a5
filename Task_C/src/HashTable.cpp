/*
 *  University of Zurich
 *  Department of Informatics
 *  Visualization and Multimedia Laboratory
 *
 *  Algorithms and Data structures
 *  Author: Genc Mazlami
 */

#include <iostream>
#include <cmath>
#include "math.h"
#include "HashTable.h"



HashTable::HashTable(){
    table = new Item*[TABLE_SIZE];
    
    //Using MAD compression map, therefore we need factors a and b
    factor_a = 7;
    factor_b = 13;
}

int HashTable::hashfunction(int key_){
    int index = (factor_a * key_  + factor_b) % TABLE_SIZE;  //compute the hash of the key using MAD compression (see slides)
    return index;
}

void HashTable::put(Item* item){
    //TODO: fill in your code here
}

Item* HashTable::get(int key_){
    //TODO: fill in your code here
}

void HashTable::putQuadratic(Item* item){
    //TODO: fill in your code here
}

Item* HashTable::getQuadratic(int key_){
    //TODO: fill in your code here
}

void HashTable::printContent(){
    std::cout << "-----------------------------" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] == NULL) {
            std::cout << i << "\t | \t" << "NULL" << std::endl;
            std::cout << "-----------------------------" << std::endl;
        }else{
            std::cout << i << "\t | \t" <<  table[i]->getName() << std::endl;
            std::cout << "-----------------------------" << std::endl;
        }
    }
    std::cout << "-----------------------------" << std::endl;
}

