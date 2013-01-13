//
//  CLRSTestCountingSort.m
//  AlgorithmsObjCTest
//
//  Created by 徐 廷 on 2013/01/08.
//  Copyright (c) 2013年 Tonny Xu. All rights reserved.
//

#import "CLRSTestCountingSort.h"
#import "CLRSCountingSort.h"

@implementation CLRSTestCountingSort

// Methods to be overridden
- (void)test{
  [super test];
  
  NSArray *testSet = [self testSet];
  [testSet enumerateObjectsUsingBlock:^(NSMutableArray *testArray, NSUInteger idx, BOOL *stop) {
    NSLog(@"Before Sort:");
    [self prettyPrint:testArray];
    
    [CLRSCountingSort sort:testArray comparator:nil];
    
    NSLog(@"After Sort:");
    [self prettyPrint:testArray];
  }];

}

- (NSString *)name{
  return @"Counting Sort";
}


@end
