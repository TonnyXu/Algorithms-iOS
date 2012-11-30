//
//  CLRS_DataStructures.h
//  algorithms-iOS
//
//  Created by Tonny Xu on 4/28/12.
//  Copyright (c) 2012 Tonny Xu. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

#ifndef _algorithms_iOS_CLRS_Tree_h_
#define _algorithms_iOS_CLRS_Tree_h_

/******************************************************************************
 * naming convesion
 * ----------------
 *
 * Tonny April 28, 2012
 *
 * put a prefix in each method to indicate what this method works for, also,
 * this naming convension helps CTag to sort the method much more clearly.
 *****************************************************************************/


/******************************************************************************
 * Binary Tree definition
 *****************************************************************************/
typedef struct BinaryTreeNode_{
  const int                *data;
  struct BinaryTreeNode_   *leftNode;
  struct BinaryTreeNode_   *rightNode;
  struct BinaryTreeNode_   *parentNode;
} BinaryTreeNode;

typedef struct BinaryTree_{
  struct BinaryTreeNode_   *rootNode;
  int                      size;
  int                      height;
} BinaryTree;


/******************************************************************************
 * Binary Tree methods
 *****************************************************************************/
BinaryTree* binaryTree_new_empty_tree();
BinaryTreeNode* binaryTree_new_node(const int *data);
void binaryTree_destroy(BinaryTree *bst);

void binaryTree_print(BinaryTree *bst);

void binaryTree_insert_data(BinaryTree *bst, const int *data);
void binaryTree_insert_node(BinaryTree *bst, BinaryTreeNode *node, BinaryTreeNode *toNode);
BinaryTreeNode *binaryTree_minimum(BinaryTree *bst);
BinaryTreeNode *binaryTree_maximum(BinaryTree *bst);


#endif

