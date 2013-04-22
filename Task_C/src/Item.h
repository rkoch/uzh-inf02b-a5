/*
 *  University of Zurich
 *  Department of Informatics
 *  Visualization and Multimedia Laboratory
 *
 *  Algorithms and Data structures
 *  Author: Genc Mazlami
 */

#ifndef hash_tables_Item_h
#define hash_tables_Item_h


#include <string>


class Item{
    
public:
    
    Item(int key_, std::string name_);
    std::string getName();
    int getKey();
    
private:
    
    std::string name;
    int key;
};






#endif
