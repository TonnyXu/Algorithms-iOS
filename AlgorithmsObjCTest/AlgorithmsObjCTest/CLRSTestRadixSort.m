//
//  CLRSTestRadixSort.m
//  AlgorithmsObjCTest
//
//  Created by 徐 廷 on 2013/01/09.
//  Copyright (c) 2013年 Tonny Xu. All rights reserved.
//

#import "CLRSTestRadixSort.h"
#import "CLRSRadixSort.h"

@implementation CLRSTestRadixSort

// Methods to be overridden
- (void)test{
  [super test];
  
  NSArray *testSet = [self testSet];
  [testSet enumerateObjectsUsingBlock:^(NSMutableArray *testArray, NSUInteger idx, BOOL *stop) {
    NSLog(@"Before Sort:");
    [self prettyPrint:testArray];
    
    [CLRSRadixSort sort:testArray comparator:nil];
    
    NSLog(@"After Sort:");
    [self prettyPrint:testArray];
  }];
  
}
- (NSString *)name{
  return @"Radix Sort";
}


@end
