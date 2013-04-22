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
#include "HashTable.h"
#include "assert.h"



int main (int argc, const char * argv[])
{
    Item* hendrix = new Item(1, "Jimmy Hendrix");
    Item* marley = new Item(16, "Bob Marley");
    Item* shakur = new Item(4, "Tupac Shakur");
    Item* cobain = new Item(46, "Kurt Cobain");
    Item* jackson = new Item(12, "Michael Jackson");
    Item* elvis = new Item(10, "Elvis Presley");
    Item* lennon = new Item(11, "John Lennon");
    Item* charles = new Item(31, "Ray Charles");
    
    HashTable hashtable = HashTable();
    
    char mode;
    std::cout << "Choose Mode: l for linear probing,  q for quadratic probing: ";
    std::cin >> mode;
    
    if (mode == 'l') {
        hashtable.put(hendrix);
        hashtable.put(marley);
        hashtable.put(jackson);
        hashtable.put(shakur);
        hashtable.put(cobain);
        hashtable.put(elvis);
        hashtable.put(charles);
        hashtable.put(lennon);
        
        hashtable.printContent();

        assert(hashtable.get(1) == hendrix);
        assert(hashtable.get(16) == marley);
        assert(hashtable.get(4) == shakur);
        assert(hashtable.get(46) == cobain);
        assert(hashtable.get(12) == jackson);
        assert(hashtable.get(10) == elvis);
        assert(hashtable.get(31) == charles);
        assert(hashtable.get(11) == lennon);
    }else if(mode == 'q'){
        hashtable.putQuadratic(hendrix);
        hashtable.putQuadratic(marley);
        hashtable.putQuadratic(jackson);
        hashtable.putQuadratic(shakur);
        hashtable.putQuadratic(cobain);
        hashtable.putQuadratic(elvis);
        hashtable.putQuadratic(charles);
        hashtable.putQuadratic(lennon);
        
        hashtable.printContent();

        assert(hashtable.getQuadratic(1) == hendrix);
        assert(hashtable.getQuadratic(16) == marley);
        assert(hashtable.getQuadratic(4) == shakur);
        assert(hashtable.getQuadratic(46) == cobain);
        assert(hashtable.getQuadratic(12) == jackson);
        assert(hashtable.getQuadratic(10) == elvis);
        assert(hashtable.getQuadratic(31) == charles);
        assert(hashtable.getQuadratic(11) == lennon);
    }
    
    return 0;
}

