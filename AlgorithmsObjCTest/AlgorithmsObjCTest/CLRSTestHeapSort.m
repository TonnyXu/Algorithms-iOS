//
//  TestHeapSort.m
//  AlgorithmsObjCTest
//
//  Created by 徐 廷 on 2012/12/18.
//  Copyright (c) 2012年 Tonny Xu. All rights reserved.
//

#import "CLRSTestHeapSort.h"
#import "CLRSSort.h"

@implementation CLRSTestHeapSort

- (NSString *)name{
  return @"Heap Sort";
}

- (void)test{
  [super test];

  NSArray *testSet = [self testSet];
  [testSet enumerateObjectsUsingBlock:^(NSMutableArray *testArray, NSUInteger idx, BOOL *stop) {
    NSLog(@"Before Sort:");
    [self prettyPrint:testArray];
    
    [CLRSHeapSort sort:testArray withComparator:^NSComparisonResult(NSNumber *obj1, NSNumber *obj2) {
      return [obj1 compare:obj2];
    }];
    
    NSLog(@"After Sort:");
    [self prettyPrint:testArray];
  }];
  
}

@end
