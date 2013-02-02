//
//  CLRSLinkedListNode.h
//  AlgorithmObjC
//
//  Created by Yi Gu on 2/2/13.
//  Copyright (c) 2013 Tonny Xu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CLRSLinkedListNode : NSObject
@property CLRSLinkedListNode *next;
@property CLRSLinkedListNode *prev;
@property id payload;
@end
