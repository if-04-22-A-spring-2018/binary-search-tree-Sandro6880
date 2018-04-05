/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			bst.cpp
 * Author(s):		Peter Bauer
 * Due Date:		May 31, 2017
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include "bst.h"
struct Node{
  Bst left_subtree;
  Bst right_subtree;
  int depth;
  int data;
};
Bst new_bst()
{
  Bst tree = 0;
  return tree;
}
void delete_bst(Bst bst)
{
  if(bst == 0)return;
  delete_bst(bst->right_subtree);
  delete_bst(bst->left_subtree);
  sfree(bst);
}

int get_depth(Bst bst)
{
  if (bst == 0)
  {
  return 0;
  }
  else if (bst->left_subtree == 0 && bst->right_subtree== 0 && bst!= 0) {
    return 1;
  }
    int depth_left = get_depth(bst->left_subtree) +1;
    int depth_right = get_depth(bst->right_subtree) +1;
    if (depth_right > depth_left)
    {
        return depth_right;
    }
    else return depth_left;
}

void add(Bst* bst, int value)
{
  Bst &copy_tree = *bst;
  if (copy_tree == 0) {
    copy_tree= (struct Node*) malloc(sizeof(struct Node));
    copy_tree->data = value;
    copy_tree->right_subtree = 0;
    copy_tree->left_subtree = 0;
    copy_tree->depth++;
    bst= &copy_tree;
  }
  else if(value <= copy_tree->data) {
    if (copy_tree->left_subtree == 0) {
      Bst new_bst = (Node*)malloc(sizeof(struct Node));
      new_bst->data = value;
      new_bst->left_subtree = 0;
      new_bst->right_subtree = 0;
      copy_tree->left_subtree = new_bst;
      copy_tree->depth++;
      bst = &copy_tree;
    }
    else
    {
      add(&copy_tree->left_subtree, value);
    }
  }
  else{
    if(copy_tree->right_subtree == 0) {
      Bst new_bst = (Node*)malloc(sizeof(struct Node));
      new_bst->data = value;
      new_bst->left_subtree = 0;
      new_bst->right_subtree = 0;
      copy_tree->right_subtree = new_bst;
      copy_tree->depth++;
      bst = &copy_tree;
    }
    else{
      add(&copy_tree->right_subtree, value);
    }
  }
}


int root_value(Bst bst)
{
  if(bst == 0)
  {
    return 0;
  }
  return bst->data;
}


int traverse_pre_order(Bst bst, int *data, int start)
{
  if(bst == 0)
  {
    return 0;
  }
  int data_count = 0;
  data[start] = bst->data;
  data_count += traverse_pre_order(bst->left_subtree, data, start+1);
  data_count+= traverse_pre_order(bst->right_subtree, data, start+data_count+1);
  return data_count+1;
}


int traverse_in_order(Bst bst, int *data, int start)
{
  if(bst == 0)
  {
    return 0;
  }
  int data_count = 0;
  data_count+= traverse_in_order(bst->left_subtree, data, start);
  data[start+data_count] = bst->data;
  data_count+= traverse_in_order(bst->right_subtree, data,start+data_count+1);
  return data_count+1;
}


int traverse_post_order(Bst bst, int *data, int start)
{
  if(bst == 0)
  {
    return 0;
  }
  int data_count = 0;
  data_count+= traverse_post_order(bst->left_subtree, data, start);
  data_count+= traverse_post_order(bst->right_subtree, data, start+data_count);
  data[start+data_count]=bst->data;
  return data_count+1;
}


bool are_equal(Bst bst1, Bst bst2)
{
  if ((bst1 == 0 && bst2==0) || bst1 == bst2) {
    return true;
  }
    int array_bst1[20];
    int array_bst2[20];
    int length_bst1 = traverse_pre_order(bst1, array_bst1, 0 );
    int length_bst2 = traverse_pre_order(bst2, array_bst2, 0 );

    if (length_bst1 == length_bst2 ) {
      bool are_equal = true;
      for (int i = 0; i < length_bst1; i++) {
        if (array_bst1[i] != array_bst2[i]) {
          are_equal = false;
        }
      }
      return are_equal;
    }
     return false;
}


void most_left_longest_branch(Bst bst, Bst* branch)
{
if (bst != 0) {
  add(branch, bst->data);
  if (get_depth(bst->left_subtree) >= get_depth(bst->right_subtree))
  {
    most_left_longest_branch(bst->left_subtree,branch);
  }
  else most_left_longest_branch(bst->right_subtree,branch);
  }
}

int get_number_of_subtrees(Bst bst)
{
  if (bst == 0) {
    return -1;
  }
  int number_of_subtrees = get_number_of_subtrees(bst->left_subtree)+1 + get_number_of_subtrees(bst->right_subtree)+1;
  return number_of_subtrees;
}


Bst left_subtree (Bst root)
{
  return root->left_subtree;
}
Bst right_subtree (Bst root)
{
  return root->right_subtree;
}
