//
//  Updated by Rafael Ballester on 09.04.12.
//  Copyright (c) 2013 Universität Zürich. All rights reserved.
//

#ifndef _AVLTREE_HPP
#define _AVLTREE_HPP_

#include <string>
#include "avl_tree_node.hpp"


class avl_tree
{
public:
  avl_tree ();
  ~avl_tree ();

  void insert (int value);
  int get_height ();
  bool is_balanced () const;

  void right_rotate_on (avl_tree_node * node);
  void left_rotate_on (avl_tree_node * node);

private:
    avl_tree_node * _root;
};

#endif // _AVLTREE_HPP_
