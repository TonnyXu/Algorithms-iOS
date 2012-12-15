//
//  CLRSHeap.h
//  AlgorithmObjC
//
//  Created by Yi Gu on 12/4/12.
//  Copyright (c) 2012 Tonny Xu. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum:NSUInteger {
    MAX_HEAP,
    MIN_HEAP,
}HeapType;

@interface CLRSHeap : NSObject
@property (readonly) NSUInteger size;

- (id)initWithType:(HeapType)type andCapacity:(NSUInteger)capacity andComparator:(NSComparator)comparator;

- (BOOL)insert:(id)object;
- (id)head;
- (id)extract;
+ (void)sort:(NSMutableArray *)array withComparator:(NSComparator)comparator;
@end

void testHeapSort();