//
//  Updated by Rafael Ballester on 09.04.12.
//  Copyright (c) 2013 Universität Zürich. All rights reserved.
//

#include "avl_tree.hpp"
#include <iostream>


int
main ()
{
  avl_tree tree;

  tree.insert (10);
  tree.insert (4);
  tree.insert (15);
  tree.insert (2);
  tree.insert (7);
  tree.insert (13);
  tree.insert (17);
  tree.insert (1);
  tree.insert (3);
  tree.insert (5);
  tree.insert (9);

  std::cout << "Tree is" << (tree.is_balanced ()? "" : " not") << " balanced." << std::endl;	// should be balanced

  std::cout << tree.get_height () << std::endl;	// should be 4
  tree.insert (6);

  std::cout << "Tree is" << (tree.is_balanced ()? "" : " not") << " balanced after insertion of '6'." << std::endl;	// should be still balanced

  return 0;
}

