//
//  CLRSTestMergeSort.m
//  AlgorithmsObjCTest
//
//  Created by 徐 廷 on 2012/12/21.
//  Copyright (c) 2012年 Tonny Xu. All rights reserved.
//

#import "CLRSTestMergeSort.h"
#import "CLRSSort.h"

@implementation CLRSTestMergeSort

- (NSString *)name{
  return @"Merge Sort";
}

- (void)test{
  
  [super test];
  
  NSArray *testSet = [self testSet];
  [testSet enumerateObjectsUsingBlock:^(NSMutableArray *testArray, NSUInteger idx, BOOL *stop) {
    NSLog(@"Before Sort:");
    [self prettyPrint:testArray];
    
    [CLRSMergeSort sort:testArray comparator:^NSComparisonResult(NSNumber *obj1, NSNumber *obj2) {
      return [obj1 compare:obj2];
    }];
    
    NSLog(@"After Sort:");
    [self prettyPrint:testArray];
  }];

//  NSMutableArray *array = [CLRSRandomGenerator randomNumbersArrayFor:20 max:100];
//  NSLog(@"Before Sort:\n[%@]", self.name);
//  [self prettyPrint:array];
//  
//  [CLRSMergeSort sort:array comparator:^NSComparisonResult(NSNumber *obj1, NSNumber *obj2) {
//    return [obj1 compare:obj2];
//  }];
//  
//  NSLog(@"After Sort:");
//  [self prettyPrint:array];

}

@end
