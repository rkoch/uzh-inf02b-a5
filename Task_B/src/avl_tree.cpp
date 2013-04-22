//
//  Updated by Rafael Ballester on 09.04.12.
//  Copyright (c) 2013 Universität Zürich. All rights reserved.
//

#include "avl_tree.hpp"


avl_tree::avl_tree ():_root (NULL)
{
}

avl_tree::~avl_tree ()
{
  delete _root;
}

void
avl_tree::insert (int value_)
{
  if (_root == NULL)
    {
      _root = new avl_tree_node (this, value_);
    }
  else
    {
      _root->insert (value_);
    }
}

int
avl_tree::get_height ()
{
  if (_root == NULL)
    {
      return 0;
    }
  else
    {
      return _root->get_height ();
    }
}

bool
avl_tree::is_balanced () const
{
  return _root->is_balanced ();
}

void
avl_tree::left_rotate_on (avl_tree_node * node_)
{
  avl_tree_node *right_child = node_->right ();
  avl_tree_node *parent_node = node_->parent ();

  if (right_child == NULL)
    return;

  node_->set_right (right_child->left ());
  right_child->set_left (node_);

  if (node_ == _root)
    {
      _root = right_child;
      _root->set_parent (NULL);
    }
  else
    {
      if (node_ == parent_node->left ())
	parent_node->set_left (right_child);
      else
	parent_node->set_right (right_child);
    }
}

void
avl_tree::right_rotate_on (avl_tree_node * node_)
{
  avl_tree_node *left_child = node_->left ();
  avl_tree_node *parent_node = node_->parent ();

  if (left_child == NULL)
    return;

  node_->set_left (left_child->right ());
  left_child->set_right (node_);

  if (node_ == _root)
    {
      _root = left_child;
      _root->set_parent (NULL);
    }
  else
    {
      if (node_ == parent_node->left ())
	parent_node->set_left (left_child);
      else
	parent_node->set_right (left_child);
    }
}
