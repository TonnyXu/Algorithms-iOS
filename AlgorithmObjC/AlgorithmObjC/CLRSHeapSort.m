//
//  CLRSHeap.m
//  AlgorithmObjC
//
//  Created by Yi Gu on 12/4/12.
//  Copyright (c) 2012 Tonny Xu. All rights reserved.
//

#import "CLRSHeapSort.h"

@interface CLRSHeapSort ()
@property (assign) HeapType type;
@property (assign) NSUInteger capacity;
@property (assign) NSUInteger size;
@property (strong) NSMutableArray *storage;
@property (copy) NSComparator comparator;
@property (assign) NSComparisonResult comparisonResult;

- (void)heapify:(NSUInteger)index;
- (void)buildHeap;
- (NSUInteger)parent:(NSUInteger)childIndex;
- (NSUInteger)left:(NSUInteger)parentIndex;
- (NSUInteger)right:(NSUInteger)parentIndex;
- (void)swapObjectAtIndex:(NSUInteger)i withObjectAtIndex:(NSUInteger)j;
@end

@implementation CLRSHeapSort
- (id)initWithType:(HeapType)type andCapacity:(NSUInteger)capacity andComparator:(NSComparator)comparator {
    self = [super init];
    if (self) {
        self.size = 0;
        self.type = type;
        self.comparisonResult = type == MAX_HEAP ? NSOrderedDescending : NSOrderedAscending;
        self.capacity = capacity;
        self.storage = [NSMutableArray arrayWithCapacity:self.capacity];
        self.comparator = comparator;
    }

    return self;
}

- (id)initWithType:(HeapType)type andArray:(NSMutableArray *)array andComparator:(NSComparator)comparator {
    self = [super init];
    if (self) {
        self.size = [array count];
        self.type = type;
        self.comparisonResult = type == MAX_HEAP ? NSOrderedDescending : NSOrderedAscending;
        self.capacity = [array count];
        self.storage = array;
        self.comparator = comparator;

        [self buildHeap];
    }

    return self;
}

#pragma mark - internal methods
- (NSUInteger)parent:(NSUInteger)childIndex {
    return childIndex == 0 ? 0 : (childIndex - 1) / 2;
}

- (NSUInteger)left:(NSUInteger)parentIndex {
    return parentIndex * 2 + 1;
}

- (NSUInteger)right:(NSUInteger)parentIndex {
    return [self left:parentIndex] + 1;
}

- (void)swapObjectAtIndex:(NSUInteger)i withObjectAtIndex:(NSUInteger)j {
    id temp = self.storage[i];
    self.storage[i] = self.storage[j];
    self.storage[j] = temp;
}

- (void)heapify:(NSUInteger)index {
    NSUInteger i = index;
    NSUInteger left = [self left:i];
    NSUInteger right = left + 1;

    if (left < self.size && self.comparator(self.storage[left], self.storage[i]) == self.comparisonResult ) {
        i = left;
    }

    if (right < self.size && self.comparator(self.storage[right], self.storage[i]) == self.comparisonResult ) {
        i = right;
    }

    if (i != index) {
        [self swapObjectAtIndex:index withObjectAtIndex:i];
        [self heapify:i];
    }
}

- (void)buildHeap {
    NSUInteger last = self.size - 1;
    for (NSUInteger i = [self parent:last]; i > 0 ; i--) {
        [self heapify:i];
    }
    [self heapify:0];
}

#pragma mark - public methods
- (BOOL)insert:(id)object {
    if (self.size == self.capacity) return NO;

    NSUInteger index = self.size;
    NSUInteger parentIndex = [self parent:index];
    self.storage[index] = object;
    self.size++;


    while (self.comparator(self.storage[index], self.storage[parentIndex]) == self.comparisonResult ) {
        [self swapObjectAtIndex:index withObjectAtIndex:parentIndex];
        index = parentIndex;
        parentIndex = [self parent:index];
    }

    return YES;
}

- (id)head {
    return self.size > 0 ? self.storage[0] : nil;
}

- (id)extract {
    if (self.size == 0) return nil;

    id object = self.storage[0];

    self.storage[0] = self.storage[self.size - 1];
    self.size--;

    [self heapify:0];

    return object;
}

+ (void)sort:(NSMutableArray *)array withComparator:(NSComparator)comparator {
  if (array == nil || array.count == 0) {
    return;
  }
    CLRSHeapSort *heap = [[CLRSHeapSort alloc] initWithType:MIN_HEAP andArray:array andComparator:comparator];

    while (heap.size > 0) {
        [heap swapObjectAtIndex:0 withObjectAtIndex:heap.size - 1];
        heap.size--;
        [heap heapify:0];
    }
}
@end

#define foo4random() (arc4random() % ((unsigned)100 + 1))
void testHeapSort() {
    NSMutableArray *data = [NSMutableArray arrayWithCapacity:20];
    for (int i = 0; i < 20; i++) {
        data[i] = @(foo4random());
    }

    NSLog(@"%@", data);

    NSComparator comparator = ^NSComparisonResult(id obj1, id obj2) {
        return [obj1 compare:obj2];
    };

    [CLRSHeap sort:data withComparator:comparator];

    NSLog(@"%@", data);

    CLRSHeap *heap = [[CLRSHeap alloc] initWithType:MAX_HEAP andCapacity:data.count andComparator:comparator];
    for (int i = 0; i < 20; i++) {
        data[i] = @(foo4random());
        [heap insert:data[i]];
    }

    NSLog(@"%@", data);

    while (heap.size > 0) {
        NSLog(@"%@", [heap extract]);
    }
}
