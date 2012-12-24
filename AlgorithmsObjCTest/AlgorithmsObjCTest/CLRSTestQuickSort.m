//
//  CLRSTestQuickSort.m
//  AlgorithmsObjCTest
//
//  Created by 徐 廷 on 2012/12/19.
//  Copyright (c) 2012年 Tonny Xu. All rights reserved.
//

#import "CLRSTestQuickSort.h"
#import "CLRSSort.h"

@implementation CLRSTestQuickSort

- (NSString *)name{
  return @"Quick Sort";
}

- (void)test{
  [super test];
  
  NSArray *testSet = [self testSet];
  [testSet enumerateObjectsUsingBlock:^(NSMutableArray *testArray, NSUInteger idx, BOOL *stop) {
    NSLog(@"Before Sort:");
    [self prettyPrint:testArray];
    
    [CLRSQuickSort sort:testArray comparator:^NSComparisonResult(NSNumber *obj1, NSNumber *obj2) {
      return [obj1 compare:obj2];
    }];
    
    NSLog(@"After Sort:");
    [self prettyPrint:testArray];
  }];
  
}

@end
