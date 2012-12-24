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

+ (NSMutableArray *)sortedNumbersArrayFor:(NSUInteger)numberOfElement order:(NSComparisonResult)order{
  NSMutableArray *array = [NSMutableArray array];
  if (order == NSOrderedAscending) {
    for (NSUInteger i=0; i < numberOfElement; i++) {
      [array addObject:@(i)];
    }
  }else{
    for (NSUInteger i=numberOfElement; i > 0; i--) {
      [array addObject:@(i)];
    }
  }
  
  return array;
}

+ (NSMutableArray *)groupedNumbersArrayFor:(NSUInteger)numberOfEachGroup groupCount:(NSUInteger)groupCount{
  NSMutableSet *set = [NSMutableSet set];
  NSUInteger i = 0;
  while (set.count < groupCount) {
    NSUInteger n = arc4random() % 1000;
    [set addObject:@(n)];
    i++;
  }
  
  NSMutableArray *array = [NSMutableArray array];
  for (NSUInteger j = 0; j < numberOfEachGroup; j++) {
    [set enumerateObjectsUsingBlock:^(NSNumber *obj, BOOL *stop) {
      [array addObject:[obj copy]];
    }];
  }
  
  return array;
}

@end
