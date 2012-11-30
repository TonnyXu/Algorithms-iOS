/*
 * Binary Tree.c
 *
 * Implement all the necessary methods for a Doubly linked list.
 */
#include "CLRS_BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>



/******************************************************************************
 * Binary Tree methods
 *****************************************************************************/
BinaryTree* binaryTree_new_empty_tree(){
  BinaryTree *bst = (BinaryTree *)malloc(sizeof(BinaryTree));
  return bst;
}

BinaryTreeNode* binaryTree_new_node(const int *data){
  BinaryTreeNode *node = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
  node->data = data;
  node->leftNode = NULL;
  node->rightNode = NULL;
  node->parentNode = NULL;
  return node;
}

void binaryTree_destroy(BinaryTree *bst){
  if (NULL != bst){
    free(bst);
  }

}

void binaryTree_print(BinaryTree *bst){

}

void binaryTree_insert_data(BinaryTree *bst, const int *data){
  if (NULL == bst) return;

  BinaryTreeNode *newNode = binaryTree_new_node(data);
  BinaryTreeNode *currentNode = bst->rootNode;

  binaryTree_insert_node(bst, newNode, currentNode);
}

void binaryTree_insert_node(BinaryTree *bst, BinaryTreeNode *node, BinaryTreeNode *toNode){
  if (NULL == bst) return;
  if (NULL == node) return;
  if (NULL == toNode) return;

  if (*toNode->data >= *node->data){
    if (toNode->leftNode != NULL){
      binaryTree_insert_node(bst, node, toNode->leftNode);
    }else{
      toNode->leftNode = node;
    }
  }else{
    if (toNode->rightNode != NULL){
      binaryTree_insert_node(bst, node, toNode->rightNode);
    }else{
      toNode->rightNode = node;
    }
  }
}


void binaryTree_delete_node(BinaryTree *bst, BinaryTreeNode *node){

}

BinaryTreeNode *binaryTree_minimum(BinaryTree *bst){
  BinaryTreeNode *currentNode = bst->rootNode;
  while (currentNode->leftNode != NULL){
    currentNode = currentNode->leftNode;
  }

  return currentNode;
}

BinaryTreeNode *binaryTree_maximum(BinaryTree *bst){
  BinaryTreeNode *currentNode = bst->rootNode;
  while (currentNode->rightNode != NULL){
    currentNode = currentNode->rightNode;
  }

  return currentNode;
}
