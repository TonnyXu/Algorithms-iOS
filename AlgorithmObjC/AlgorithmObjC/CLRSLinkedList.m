//
//  CLRSLinkedList.m
//  AlgorithmObjC
//
//  Created by Yi Gu on 1/19/13.
//  Copyright (c) 2013 Tonny Xu. All rights reserved.
//

#import "CLRSLinkedList.h"
#import "CLRSLinkedListNode.h"
@interface CLRSLinkedList ()
@property CLRSLinkedListNode *sentinel;
@end


@implementation CLRSLinkedList
- (id)init {
    self = [super init];
    if (self) {
        CLRSLinkedListNode *sentinel = [CLRSLinkedListNode new];
        sentinel.payload = @"(sentinel)";
        sentinel.next = sentinel;
        sentinel.prev = sentinel;
        self.sentinel = sentinel;
    }
    return self;
}

- (CLRSLinkedListNode *)nodeWithObject:(id)object {
    CLRSLinkedListNode *node = [CLRSLinkedListNode new];
    node.payload = object;

    return node;
}

- (CLRSLinkedListNode *)searchForNodeContainsObject:(id)object {
    CLRSLinkedListNode *node = self.sentinel.next; //head
    while (node != self.sentinel && [node.payload isNotEqualTo:object]) {
        node = node.next;
    }
    return node;
}

- (id)search:(id)object {
    CLRSLinkedListNode *node = [self searchForNodeContainsObject:object];
    if (node == self.sentinel) return nil;
    
    return node.payload;
}

- (void)insert:(id)object {
    CLRSLinkedListNode *node = [self nodeWithObject:object];

    node.next = self.sentinel.next;
    self.sentinel.next.prev = node;

    self.sentinel.next = node;
    node.prev = self.sentinel;
}

- (void)remove:(id)object {
    CLRSLinkedListNode *node = [self searchForNodeContainsObject:object];
    if (node == self.sentinel) return;

    node.prev.next = node.next;
    node.next.prev = node.prev;
}

- (NSString *)description {
    CLRSLinkedListNode *node = self.sentinel;
    NSMutableString *output = [NSMutableString new];
    while (node = node.next, node != self.sentinel) {
        [output appendFormat:@"[ %@ ] -> ", node.payload];
    }
    [output appendString:@"nil."];

    return output;
}
@end
