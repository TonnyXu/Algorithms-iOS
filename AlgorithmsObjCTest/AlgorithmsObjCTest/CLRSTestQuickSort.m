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
  NSMutableArray *array = [CLRSRandomGenerator randomNumbersArrayFor:20 max:100];
  
  NSLog(@"Before Sort:\n[%@]", self.name);
  [self prettyPrint:array];
  
  [CLRSQuickSort sort:array comparator:^NSComparisonResult(NSNumber *obj1, NSNumber *obj2) {
    return [obj1 compare:obj2];
  }];
  
  NSLog(@"After Sort:");
  [self prettyPrint:array];
}

@end
