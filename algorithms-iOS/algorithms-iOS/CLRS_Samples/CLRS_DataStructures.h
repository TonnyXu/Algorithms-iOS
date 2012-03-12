//
//  CLRS_DataStructures.h
//  algorithms-iOS
//
//  Created by Tonny Xu on 2/9/12.
//  Copyright (c) 2012 Tonny Xu. All rights reserved.
//

#ifndef algorithms_iOS_CLRS_DataStructures_h
#define algorithms_iOS_CLRS_DataStructures_h

typedef struct{
  Node *nextNode;
  Node *prevNode;
  int key;
  void *obj;
} Node;

typedef struct{
  TreeNode *leftNode;
  TreeNode *rightNode;
  TreeNode *pNode;
  int key;
} TreeNode;



#endif
