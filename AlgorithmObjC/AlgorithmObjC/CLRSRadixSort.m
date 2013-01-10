//
//  CLRSRadixSort.m
//  AlgorithmObjC
//
//  Created by 徐 廷 on 2012/12/20.
//  Copyright (c) 2012年 Tonny Xu. All rights reserved.
//

#import "CLRSRadixSort.h"
#import "CLRSMergeSort.h"

@interface CLRSRadixSort ()

- (NSUInteger)maxValueFrom:(NSArray *)array;

@end

@implementation CLRSRadixSort

- (NSUInteger)maxValueFrom:(NSArray *)array{
  __block NSUInteger max = 0;
  [array enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL *stop) {
    if (![obj isKindOfClass:[NSNumber class]]) {
      [NSException raise:NSInvalidArgumentException format:@"Contains non-NSNumber object: %@", obj];
    }
    
    NSNumber *number = (NSNumber *)obj;
    if (max < number.unsignedIntegerValue) {
      max = number.unsignedIntegerValue;
    }
  }];
  
  return max;
  
}

/* Tonny NOTE
 * ------------
 * Jan 10, 2013
 * 
 * This code is an implementation inspired by http://en.wikipedia.org/wiki/Radix_sort#Example_in_C
 * 
 */
+ (void)sort:(NSMutableArray *)data comparator:(NSComparator)comparator{
  if (data.count == 0) {
    return;
  }
  CLRSRadixSort *radixSort = [CLRSRadixSort new];
  
  // If there is an unexpected value, an exception will be raised inside this function.
  NSUInteger max = [radixSort maxValueFrom:data];
  NSUInteger dataCount = data.count;
  NSUInteger tempDataArray[dataCount];
  
  NSUInteger scaleValues[dataCount];
  for (int i = 0; i < dataCount; i++) {
    NSNumber *number = data[i];
    scaleValues[i] = number.unsignedIntegerValue;
    tempDataArray[i] = 0;
  }
  
  NSUInteger exp = 1;
  
  while (max / exp > 0) {
    NSUInteger bucket[10] = {0};
    for (int i = 0; i < dataCount; i++) {
      bucket[scaleValues[i] / exp % 10]++;
    }
    for (int i = 1; i < 10; i++) {
      bucket[i] += bucket[i-1];
    }
    for (int i = (int)(dataCount - 1); i >= 0; i--) {
      tempDataArray[--bucket[scaleValues[i] / exp % 10]] = scaleValues[i];
    }
    for (int i = 0; i < dataCount; i++) {
      scaleValues[i] = tempDataArray[i];
    }
    
    exp *= 10;
  }
  
  for (int i = 0; i < dataCount; i++) {
    data[i] = @(tempDataArray[i]);
  }
}

@end
