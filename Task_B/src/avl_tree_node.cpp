//
//  Updated by Rafael Ballester on 09.04.12.
//  Copyright (c) 2013 Universität Zürich. All rights reserved.
//

#include <cmath>
#include "avl_tree_node.hpp"
#include "avl_tree.hpp"

avl_tree_node::avl_tree_node (avl_tree * tree_, int value_):
_tree (tree_),
_value (value_),
_parent (NULL),
_left (NULL),
_right (NULL)
{
}

avl_tree_node::~avl_tree_node ()
{
  delete _left;
  delete _right;
}

void
avl_tree_node::set_left (avl_tree_node * left_)
{
  _left = left_;
  _left->set_parent (this);
}

void
avl_tree_node::set_right (avl_tree_node * right_)
{
  _right = right_;
  _right->set_parent (this);
}

void
avl_tree_node::set_parent (avl_tree_node * parent_)
{
  _parent = parent_;
}

avl_tree_node *
avl_tree_node::left () const
{
  return _left;
}

avl_tree_node *
avl_tree_node::right () const
{
  return _right;
}

avl_tree_node *
avl_tree_node::parent () const
{
  return _parent;
}

void
avl_tree_node::insert (int value_)
{
    //TODO: fill in your code here
}

bool
avl_tree_node::is_balanced () const
{
    //TODO: fill in your code here
}

int
avl_tree_node::get_height () const
{
    //TODO: fill in your code here
}

void
avl_tree_node::restructure ()
{
  int balance_factor = balance ();

  if (balance_factor <= -2)
    {
      int right_balance = _right->balance ();

      if (right_balance == -1)
	{
	  _tree->left_rotate_on (this);
	  _tree->left_rotate_on (_right);
	}
      else if (right_balance < 0)
	{
	  _tree->left_rotate_on (this);
	}
      else if (right_balance == 1)
	{
	  _tree->right_rotate_on (_right);
	  _tree->left_rotate_on (this);
	}
    }
  else if (balance_factor >= 2)
    {
      int left_balance = _left->balance ();

      if (left_balance == 1)
	{
	  _tree->right_rotate_on (this);
	  _tree->right_rotate_on (_left);
	}
      else if (left_balance > 0)
	{
	  _tree->right_rotate_on (this);
	}
      else if (left_balance == -1)
	{
	  _tree->left_rotate_on (_left);
	  _tree->right_rotate_on (this);
	}
    }

  if (parent () != NULL)
    {
      parent ()->restructure ();
    }
}

int
avl_tree_node::balance () const
{
  int left_height = _left == NULL ? 0 : _left->get_height ();
  int right_height = _right == NULL ? 0 : _right->get_height ();

  return left_height - right_height;
}
