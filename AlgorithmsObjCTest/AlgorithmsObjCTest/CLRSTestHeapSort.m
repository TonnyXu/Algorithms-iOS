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
  NSMutableArray *array = [CLRSRandomGenerator randomNumbersArrayFor:20 max:100];
  
  NSLog(@"Before Sort:\n[%@]", self.name);
  [self prettyPrint:array];
  
  [CLRSHeapSort sort:array withComparator:^NSComparisonResult(NSNumber *obj1, NSNumber *obj2) {
    return [obj1 compare:obj2];
  }];
  
  NSLog(@"After Sort:");
  [self prettyPrint:array];
  
}

@end
