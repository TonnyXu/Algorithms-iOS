//
//  CLRSRandomGenerator.m
//  AlgorithmObjC
//
//  Created by Tonny Xu on 12/17/12.
//  Copyright (c) 2012 Tonny Xu. All rights reserved.
//

#import "CLRSRandomGenerator.h"

@implementation CLRSRandomGenerator

+ (NSMutableArray *)randomNumbersArrayFor:(NSUInteger)numberOfElement max:(NSUInteger)maxValue{
  NSMutableArray *array = [NSMutableArray array];
  
  if (numberOfElement == 0) {
    return array;
  }
  
  for (int i = 0; i < numberOfElement; i++) {
    NSUInteger random = arc4random() % maxValue;
    [array addObject:@(random)];
  }
  
  return array;
}

@end
