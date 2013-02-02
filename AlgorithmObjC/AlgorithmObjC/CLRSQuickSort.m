//
//  CLRSQuickSort.m
//  AlgorithmObjC
//
//  Created by Tonny Xu on 12/15/12.
//  Copyright (c) 2012 Tonny Xu. All rights reserved.
//

#import "CLRSQuickSort.h"

@interface CLRSQuickSort ()

- (void)quicksort:(NSMutableArray *)data startAt:(NSUInteger)sIndex endAt:(NSUInteger)eIndex comparator:(NSComparator)comparator;
- (NSUInteger)partitionData:(NSMutableArray *)data startAt:(NSUInteger)lpIndex endAt:(NSUInteger)rpIndex comparator:(NSComparator)comparator;

@end

@implementation CLRSQuickSort

+ (void)sort:(NSMutableArray *)data comparator:(NSComparator)comparator{
  if (nil == data || nil == comparator || data.count == 0 || data.count == 1) {
    return;
  }

  NSUInteger firstRandomPivotIndex = arc4random() % data.count;
  id tempData = data[data.count -1];
  data[data.count -1] = data[firstRandomPivotIndex];
  data[firstRandomPivotIndex] = tempData;
  CLRSQuickSort *quickSorter = [CLRSQuickSort new];
  [quickSorter quicksort:data startAt:0 endAt:data.count-1 comparator:comparator];
}

- (void)quicksort:(NSMutableArray *)data startAt:(NSUInteger)sIndex endAt:(NSUInteger)eIndex comparator:(NSComparator)comparator{
  
  NSUInteger pIndex = [self partitionData:data startAt:sIndex endAt:eIndex comparator:comparator];
  if (pIndex > (sIndex+1)) {
    [self quicksort:data startAt:sIndex endAt:pIndex-1 comparator:comparator];
  }
  if (pIndex < (eIndex-1)) {
    [self quicksort:data startAt:pIndex+1 endAt:eIndex comparator:comparator];
  }
}

/* Tonny NOTE
 * ----------
 * Jan 19, 2013
 * 
 * See CLRS page.171 for detail.
 * 
 * The index calculation is pretty tricky. The following one could be the best.
 * 
 */
- (NSUInteger)partitionData:(NSMutableArray *)data startAt:(NSUInteger)sIndex endAt:(NSUInteger)eIndex comparator:(NSComparator)comparator{
  // randomize the pivot element.
  NSUInteger randomIndex = arc4random()%(eIndex - sIndex) + sIndex;
  id randomObj = data[randomIndex];
  data[randomIndex] = data[eIndex];
  data[eIndex] = randomObj;

  // normal quicksort algorithm
  id endObj = data[eIndex];
  NSInteger pIndex = sIndex -1;
  
  for (NSUInteger j = sIndex; j < eIndex; j++) {
    id currentObj = data[j];
    NSComparisonResult compareResult = comparator(currentObj, endObj);
    if (compareResult == NSOrderedAscending || compareResult == NSOrderedSame) {
      pIndex++;
      // when pIndex == j, no need to do the swap.
      if (pIndex != j) {
        data[j] = data[pIndex];
        data[pIndex] = currentObj;
      }
    }
  }
  
  // pIndex + 1 is the next pivot element
  data[eIndex] = data[pIndex + 1];
  data[pIndex + 1] = endObj;
  
  return pIndex + 1;
}

//- (NSUInteger)partitionData:(NSMutableArray *)data startAt:(NSUInteger)sIndex endAt:(NSUInteger)eIndex comparator:(NSComparator)comparator{
//  // one element
//  if (eIndex == sIndex) {
//    return eIndex;
//  }
//  
//  // only 2 elements
//  if (eIndex - sIndex == 1) {
//    NSComparisonResult compareResult = comparator(data[sIndex], data[eIndex]);
//    if (compareResult == NSOrderedSame || compareResult == NSOrderedAscending) {
//      return eIndex;
//    }else{
//      id tempData = data[eIndex];
//      data[eIndex] = data[sIndex];
//      data[sIndex] = tempData;
//      return eIndex;
//    }
//  }
//  
//  // More than 3 elements
//  /*
//   *  s            e        s           e        s           e        s           e     
//   * +---+---+---+---+    +---+---+---+---+    +---+---+---+---+    +---+---+---+---+   
//   * | 1 |   |   | 5 | -> | 1 | 2 |   | 5 | -> | 1 | 2 | 3 | 5 | -> | 1 | 2 | 3 | 5 | ->
//   * +---+---+---+---+    +---+---+---+---+    +---+---+---+---+    +---+---+---+---+   
//   *  w                         w                        w                        w
//   *  p                         p                        p                        p
//   *======
//   *  s            e        s           e        s           e        s           e     
//   * +---+---+---+---+    +---+---+---+---+    +---+---+---+---+    +---+---+---+---+   
//   * | 6 |   |   | 5 | -> | 6 | 4 |   | 5 | -> | 4 | 6 | 3 | 5 | -> | 4 | 3 | 6 | 5 | ->
//   * +---+---+---+---+    +---+---+---+---+    +---+---+---+---+    +---+---+---+---+   
//   *  w                         w                        w                        w
//   *  p                     p                        p                        p
//   *======
//   *  s            e        s           e        s           e        s           e        s           e     
//   * +---+---+---+---+    +---+---+---+---+    +---+---+---+---+    +---+---+---+---+    +---+---+---+---+   
//   * | 6 |   |   | 5 | -> | 6 | 7 |   | 5 | -> | 6 | 7 | 8 | 5 | -> | 6 | 7 | 8 | 5 | -> | 5 | 7 | 8 | 6 |
//   * +---+---+---+---+    +---+---+---+---+    +---+---+---+---+    +---+---+---+---+    +---+---+---+---+   
//   *  w                         w                        w                        w                    w
//   *  p                     p                    p                    p                    p
//   *======
//   *  s            e        s           e        s           e        s           e        s           e     
//   * +---+---+---+---+    +---+---+---+---+    +---+---+---+---+    +---+---+---+---+    +---+---+---+---+   
//   * | 4 |   |   | 5 | -> | 4 | 6 |   | 5 | -> | 4 | 6 | 7 | 5 | -> | 4 | 6 | 7 | 5 | -> | 4 | 5 | 7 | 6 |
//   * +---+---+---+---+    +---+---+---+---+    +---+---+---+---+    +---+---+---+---+    +---+---+---+---+   
//   *  w                         w                        w                        w                    w
//   *  p                         p                    p                    p                    p
//   *======
//   *  s            e        s           e
//   * +---+---+---+---+    +---+---+---+---+    
//   * | 5 | 5 | 5 | 5 | -> | 5 | 5 | 5 | 5 | ->
//   * +---+---+---+---+    +---+---+---+---+  
//   *  w                         w
//   *  p                         p
//   */
//  NSUInteger movingIndex = sIndex;
//  NSUInteger pIndex = sIndex;
//
//  while (movingIndex < eIndex) {
//    NSComparisonResult compareResult = comparator(data[movingIndex], data[eIndex]);
//    if (compareResult == NSOrderedAscending || compareResult == NSOrderedSame) {
//      if (pIndex < movingIndex) {
//        id tempData = data[movingIndex];
//        data[movingIndex] = data[pIndex];
//        data[pIndex] = tempData;
//      }
//      pIndex++;
//    }
//    
//    movingIndex++;
//    
//  }
//  
//  if (pIndex < eIndex) {
//    //exchange pivot element and p element
//    id tempData = data[eIndex];
//    data[eIndex] = data[pIndex];
//    data[pIndex] = tempData;
//  }
//  
//  return pIndex;
//  
//}


@end
