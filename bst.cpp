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

/**
*** Initializes the binary search tree. Deletes all existing nodes in the tree
*** @return The number of deleted nodes
*/
Bst new_bst(){
  Bst root = (struct Node*)malloc(sizeof(Bst));

  return root;
}

void delete_bst(Bst bst){

}

/**
*** @return The depth of the BST
*/
int get_depth(Bst bst){
  return 0;
}

/**
*** Adds a value to the BST
*/
void add(Bst* bst, int value){
  if(bst == 0)
  {
    bst = (struct Node*)malloc(sizeof(Bst));
    bst->data = value;
  }
}

/**
*** @return The value of the root element of the BST
*/
int root_value(Bst bst){

}

/**
*** @return The left subtree of the BST
*/
Bst left_subtree(Bst root){

}

/**
*** @return The right subtree of the BST
*/
Bst right_subtree(Bst root){

}

/**
*** Traverses the BST depth first by first returning the root, then traversing the left
*** subtree, then traversing the right subtree.
*** @param bst The BST to be traversed
*** @param elements Array of elements in the order how they are found during traversal
*** @param start Start index of elements wherer the function should start to add the found elements
*** @return Number of elements found during traversal
*/
int traverse_pre_order(Bst bst, int *elements, int start){
  return 0;
}

/**
*** Traverses the BST depth first by first traversing the left subtree, then adding the root,
*** then traversing the right subtree.
*** @param bst The BST to be traversed
*** @param elements Array of elements in the order how they are found during traversal
*** @param start Start index of elements wherer the function should start to add the found elements
*** @return Number of elements found during traversal
*/
int traverse_in_order(Bst bst, int *elements, int start){
  return 0;
}

/**
*** Traverses the BST depth first by first traversing the left subtree, then traversing the right
*** subtree and finally adding the root.
*** @param bst The BST to be traversed
*** @param elements Array of elements in the order how they are found during traversal
*** @param start Start index of elements wherer the function should start to add the found elements
*** @return Number of elements found during traversal
*/
int traverse_post_order(Bst bst, int *elements, int start){
  return 0;
}

/**
*** Checks whether two trees are equal
*** @param bst1 First bst
*** @param bst2 Second bst
*** @return true if bst1 and bst2 are equal, false otherwise
*/
bool are_equal(Bst bst1, Bst bst2){
  return true;
}

/**
*** Calculates the longest branch in the tree. If two branches are equally long
*** the left branch is taken.
*** @param bst Bst which longest branch should be found
*** @return A tree where each node has only one child equal to the longest
*** branch of bst
*/
void most_left_longest_branch(Bst bst, Bst* branch){

}

/**
*** Gets the number of non-empty subtrees of a tree
*** @param bst The tree which number of subtrees to get
*** @return The number of non-empty subtrees
*/
int get_number_of_subtrees(Bst bst)
{
  return true;
}
