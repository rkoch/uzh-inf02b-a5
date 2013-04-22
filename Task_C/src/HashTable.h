/*
 *  University of Zurich
 *  Department of Informatics
 *  Visualization and Multimedia Laboratory
 *
 *  Algorithms and Data structures
 *  Author: Genc Mazlami
 */

#ifndef hash_tables_HashTable_h
#define hash_tables_HashTable_h

#include "Item.h"
#include <vector>

const int TABLE_SIZE = 15;

class HashTable{
    
public:
    
    HashTable();
    int hashfunction(int key_);
    Item* get(int key_);
    void put(Item* item);
    Item* getQuadratic(int key_);
    void putQuadratic(Item* item);
    void printContent();
    
private:
    
    int factor_a;
    int factor_b;

    Item** table;
};

#endif
