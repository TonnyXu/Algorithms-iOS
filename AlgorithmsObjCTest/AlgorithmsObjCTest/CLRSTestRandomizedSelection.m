//
//  CLRSTestRandomizedSelection.m
//  AlgorithmsObjCTest
//
//  Created by Yi Gu on 1/14/13.
//  Copyright (c) 2013 Tonny Xu. All rights reserved.
//

#import "CLRSTestRandomizedSelection.h"
#import "CLRSRandomizedSelection.h"

@implementation CLRSTestRandomizedSelection
- (NSString *)name{
    return @"Randomized Selection";
}

- (void)test{
    [super test];

    NSComparator comparator = ^NSComparisonResult(id obj1, id obj2) {
        return [obj1 compare:obj2];
    };
    
    NSArray *testSet = [self testSet];
    [testSet enumerateObjectsUsingBlock:^(NSMutableArray *testArray, NSUInteger idx, BOOL *stop) {
        if (!testArray.count) return;

        NSUInteger n = arc4random() % testArray.count;

        NSArray *sortedArray = [testArray sortedArrayUsingComparator:comparator];
        [self prettyPrint:sortedArray];
        
        id object = sortedArray[n - 1];

        id element = [CLRSRandomizedSelection selectNth:n fromArray:testArray withComparator:comparator];

        if ([object isEqual:element]) {
            NSLog(@"The %ldth element is %@", n, element);
        }
    }];
    
}
@end
