//
//  CLRSCountingSort.m
//  AlgorithmObjC
//
//  Created by 徐 廷 on 2012/12/20.
//  Copyright (c) 2012年 Tonny Xu. All rights reserved.
//

#import "CLRSCountingSort.h"

@interface CLRSCountingSort ()

- (NSUInteger)maxValueForArray:(NSArray *)array;

@end

@implementation CLRSCountingSort

- (NSUInteger)maxValueForArray:(NSArray *)array{
  __block NSUInteger max = 0;
  [array enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL *stop) {
    if (![obj isKindOfClass:[NSNumber class]]) {
      NSAssert(false, @"You should not put non-NSNumber object in the data array");
    }
    
    NSInteger value = [obj integerValue];
    if (value < 0) {
      NSAssert(false, @"Counting sort only support non-negative numbers.");
    }
    
    if (value > max) {
      max = value;
    }
  }];
  
  return max;
}


+ (void)sort:(NSMutableArray *)data comparator:(NSComparator)comparator{
  if (data == nil || data.count == 0) {
    return;
  }
  
  CLRSCountingSort *countingSort = [CLRSCountingSort new];
  NSUInteger max = [countingSort maxValueForArray:data] + 1; // If the data contains number less than 0, it will crash here. `+1` is to make sure the max value can be used as index.
  // Objective-C forbade us to manipulate the array during block based enumration. so we have to use the basic C array type.
  NSUInteger valueArray[max];
  
  for (int i=0; i<max; i++) {
    valueArray[i] = 0;
  }
  
  // First loop: counting each element in a new array with index=value
  for (int i=0; i<data.count; i++) {
    NSNumber *value = data[i];
    valueArray[value.intValue]++;
  }
  
  // Second loop: calculate new array's start index for each element
  for (int i=1; i<max; i++) {
    valueArray[i] += valueArray[i-1];
  }
  
  // 2.5 loop: generate an empty data array for NSArray to hold temp zero value.
  NSMutableArray *newData = [NSMutableArray array];
  for (int i=0; i<data.count; i++) {
    [newData addObject:@(0)];
  }
  
  // Third loop: generate the sorted array
  for (int i=0; i<data.count; i++) {
    NSNumber *value = data[i];
    NSUInteger index = valueArray[value.integerValue];
    newData[index-1] = value;
    valueArray[value.integerValue]--;
  }
  
  // Final loop: for Objective-C, we need to replace the data in original array.
  for (int i=0; i<data.count; i++) {
    data[i] = newData[i];
  }
}

@end
