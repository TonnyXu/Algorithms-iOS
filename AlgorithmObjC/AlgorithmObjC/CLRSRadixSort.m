//
//  CLRSRadixSort.m
//  AlgorithmObjC
//
//  Created by 徐 廷 on 2012/12/20.
//  Copyright (c) 2012年 Tonny Xu. All rights reserved.
//

#import "CLRSRadixSort.h"

@interface CLRSRadixSort ()

- (NSString *)digitAtLSDIndex:(NSUInteger)digitIdx for0PaddingNumberString:(NSString *)numberString;
- (NSString *)digitAtMSDIndex:(NSUInteger)digitIdx for0PaddingNumberString:(NSString *)numberString;

@end

@implementation CLRSRadixSort

/* NOTE By Tonny
 * -------------
 * Jan 9, 2013
 *
 * LSD = Least Significent Digit, say we have a number 12345, the LSD index is like:
 *
 * 1 2 3 4 5
 * ---------
 * 4 3 2 1 0
 *
 * Since we are dealing with NSUInteger, in 32bit system, we can handle
 * #define INT32_MAX        2147483647               max LSDIndex = 9 (10 digits)
 * #define INT64_MAX        9223372036854775807LL    max LSDIndex = 18 (19 digits)
 *
 *
*/
- (NSString *)digitAtLSDIndex:(NSUInteger)digitIdx for0PaddingNumberString:(NSString *)numberString{
  if (digitIdx > 18 || numberString.length != 19) {
    return @"0";
  }
  
  NSString *digit = [numberString substringWithRange:NSMakeRange(19 - digitIdx -1, 1)];
  return digit;
}
- (NSString *)digitAtMSDIndex:(NSUInteger)digitIdx for0PaddingNumberString:(NSString *)numberString{
  if (digitIdx > 18) {
    return @"0";
  }
  
  NSString *digit = [numberString substringWithRange:NSMakeRange(digitIdx, 1)];
  return digit;
}

+ (void)sort:(NSMutableArray *)data comparator:(NSComparator)comparator{
  if (data.count == 0) {
    return;
  }
  
  CLRSRadixSort *radixSort = [CLRSRadixSort new];
  /* NOTE By Tonny
   * -------------
   * Jan 9, 2013
   *
   * In order to get the digit at position `n`, turn the number into 0 padding string will be a good idea.
   *
   */
  NSMutableArray *dataStrArray = [NSMutableArray array];
  __block NSUInteger maxNumberLength = 0;
  [data enumerateObjectsUsingBlock:^(NSNumber *number, NSUInteger idx, BOOL *stop) {
    NSUInteger strLen = number.stringValue.length;
    if (maxNumberLength < strLen) {
      maxNumberLength = strLen;
    }
    [dataStrArray addObject:@{@"number":[NSString stringWithFormat:@"%019ld", number.integerValue], @"index":@(idx)}];
  }];
  
  while (TRUE) {
    NSMutableSet *digitSet = [NSMutableSet set];
    NSMutableArray *digitArray = [NSMutableArray array];
    NSUInteger idx = 0;
    [dataStrArray enumerateObjectsUsingBlock:^(NSDictionary *dict, NSUInteger idx, BOOL *stop) {
      NSString *digit = [radixSort digitAtLSDIndex:idx for0PaddingNumberString:dict[@"number"]];
      [digitSet addObject:digit];
      [digitArray addObject:@{@"digit": digit, @"index":dict[@"index"]}];
    }];
    idx++;
    
    // only one digit for all number, no need to do
    if (digitSet.count == 0) {
      break;
    }
    
    if (idx >= maxNumberLength) {
      break;
    }
    
    // insert sort to handle each digit, and adjust the position in origin array.
    
  }
}

@end
