//
//  CLRSRandomizedSelection.m
//  AlgorithmObjC
//
//  Created by Yi Gu on 1/13/13.
//  Copyright (c) 2013 Tonny Xu. All rights reserved.
//

#import "CLRSRandomizedSelection.h"

@interface CLRSRandomizedSelection ()
@property (nonatomic, strong) NSComparator comparator;
@property (nonatomic, strong) NSMutableArray *elements;
@property (nonatomic, assign) NSUInteger position;
@end

@implementation CLRSRandomizedSelection
+ (id)selectNth:(NSUInteger)n fromArray:(NSArray *)array withComparator:(NSComparator)comparator {
    if (array.count == 0) return nil;

    CLRSRandomizedSelection *selector = [CLRSRandomizedSelection new];
    selector.comparator = comparator;
    selector.elements = [array mutableCopy];
    selector.position = n - 1;

    NSUInteger index = [selector selectFromIndex:0 toIndex:selector.elements.count - 1];
    return selector.elements[index];
}

- (NSUInteger)selectFromIndex:(NSUInteger)from toIndex:(NSUInteger)to {
    NSUInteger pivotIndex = [self randomizedPartitionFromIndex:from toIndex:to];

    if (pivotIndex == self.position) return pivotIndex;

    if (pivotIndex > self.position) {
        return [self selectFromIndex:from toIndex:pivotIndex - 1];
    } else {
        return [self selectFromIndex:pivotIndex + 1 toIndex:to];
    }

}

- (NSUInteger)randomizedPartitionFromIndex:(NSUInteger)from toIndex:(NSUInteger)to {
    NSUInteger size = (to - from + 1);
    NSUInteger randomIndex = (size == 0 ? 0 : arc4random() % size) + from;
    [self.elements exchangeObjectAtIndex:to withObjectAtIndex:randomIndex];

    return [self partitionFromIndex:from toIndex:to];
}


//The implementation is introduced on P.171 of CLRS 3rd.  
- (NSUInteger)partitionFromIndex:(NSUInteger)from toIndex:(NSUInteger)to {
    if (to - from <= 1) return from;

    id pivotElement = self.elements[to];

    //        3, 7, 6, 2, 4
    // #0  L  R  ->       P
    // #1     LR
    // (swap) 3, 7, 6, 2, 4
    //        L  R  ->    P
    // #2     L     R  -> P
    // #3        L     R  P
    // (swap) 3, 2, 6, 7, 4
    //           L        RP
    // (final)3, 2, 4, 7, 6
    //              ^
    //              |
    //              `-> returned index
    NSUInteger left = from - 1;
    for (NSUInteger right = from; right < to; right++) {
        if (self.comparator(self.elements[right], pivotElement) != NSOrderedDescending) {
            left += 1;
            [self.elements exchangeObjectAtIndex:left withObjectAtIndex:right];
        }
    }
    [self.elements exchangeObjectAtIndex:left + 1 withObjectAtIndex:to];
    return left + 1;
}
@end
