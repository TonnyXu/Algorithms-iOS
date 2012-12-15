//
//  main.m
//  CLRSHeapTest
//
//  Created by Tonny Xu on 12/15/12.
//  Copyright (c) 2012 Tonny Xu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CLRSHeap.h"

int main(int argc, const char * argv[])
{
  
  @autoreleasepool {
    
    NSMutableArray *array = [@[@(100), @(1), @(99), @(2), @(98), @(3), @(97), @(4), @(96), @(5)] mutableCopy];
//    NSMutableArray *array2 = [array copy];
    NSLog(@"Before sort: %@", array);
    [CLRSHeap sort:array withComparator:^NSComparisonResult(NSNumber *obj1, NSNumber *obj2) {
      return [obj1 compare:obj2];
    }];
    
    NSLog(@"After sort: %@", array);
    
//    CLRSHeap *heap =
//    [[CLRSHeap alloc] initWithType:MIN_HEAP
//                       andCapacity:10
//                     andComparator:^NSComparisonResult(NSNumber *obj1, NSNumber *obj2) {
//                       return [obj1 compare:obj2];
//                     }];
//    [array2 enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL *stop) {
//      [heap insert:obj];
//    }];
    
  }
  return 0;
}

