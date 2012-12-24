//
//  CLRSMergeSort.m
//  AlgorithmObjC
//
//  Created by 徐 廷 on 2012/12/20.
//  Copyright (c) 2012年 Tonny Xu. All rights reserved.
//

#import "CLRSMergeSort.h"

@interface CLRSMergeSort ()

// Divide
- (NSArray *)mergeSort:(NSArray *)data comparator:(NSComparator)comparator;
// Conquer
- (NSMutableArray *)merge:(NSArray *)data1 and:(NSArray *)data2 comparator:(NSComparator)comparator;

@end

@implementation CLRSMergeSort

+ (void)sort:(NSMutableArray *)data comparator:(NSComparator)comparator{
  CLRSMergeSort *mergeSort = [CLRSMergeSort new];
  NSArray *array = [mergeSort mergeSort:data comparator:comparator];
  [data removeAllObjects];
  [data addObjectsFromArray:array];
}

- (NSArray *)mergeSort:(NSArray *)data comparator:(NSComparator)comparator{
  if (data == nil || data.count == 0 || data.count == 1) {
    return [NSArray arrayWithArray:data];
  }
  
  if (data.count > 2) {
    // keep deviding
    NSUInteger left = data.count >> 1;
    NSArray *leftArray = [self mergeSort:[data subarrayWithRange:NSMakeRange(0, left)] comparator:comparator];
    NSArray *rightArray = [self mergeSort:[data subarrayWithRange:NSMakeRange(left, data.count-left)] comparator:comparator];
    
    return [self merge:leftArray and:rightArray comparator:comparator];
  }else{
    // sort this 2 element
    if (comparator(data[0], data[1]) == NSOrderedDescending) {
      return @[data[1], data[0]];
    }else{
      return [data copy];
    }
  }
}

- (NSMutableArray *)merge:(NSMutableArray *)data1 and:(NSMutableArray *)data2 comparator:(NSComparator)comparator{
  if (data1.count == 0 && data2.count != 0) {
    return data2;
  }else if (data1.count != 0 && data2.count == 0){
    return data1;
  }else if (data1.count == 0 && data2.count == 0){
    return [NSMutableArray array];
  }
  
  // data1.count > 0 && data2.count > 0
  NSMutableArray *resultArray = [NSMutableArray array];
  NSUInteger idx1 = 0, idx2 = 0;
  while (idx1 < data1.count || idx2 < data2.count) {
    if (idx1 == data1.count && idx2 < data2.count) {
      [resultArray addObject:data2[idx2]];
      idx2++;
    }else if (idx1 < data1.count && idx2 == data2.count){
      [resultArray addObject:data1[idx1]];
      idx1++;
    }else if (idx1 < data1.count && idx2 < data2.count){
      id obj1 = data1[idx1];
      id obj2 = data2[idx2];
      if ([obj1 compare:obj2] == NSOrderedAscending) {
        [resultArray addObject:obj1];
        idx1++;
      }else if ([obj1 compare:obj2] == NSOrderedDescending){
        [resultArray addObject:obj2];
        idx2++;
      }else{
        [resultArray addObject:obj1];
        [resultArray addObject:obj2];
        idx1++;
        idx2++;
      }
    }
    
  }
  
  
  return resultArray;
}


@end
