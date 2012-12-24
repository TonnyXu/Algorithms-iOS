//
//  CLRSTest.m
//  AlgorithmsObjCTest
//
//  Created by 徐 廷 on 2012/12/18.
//  Copyright (c) 2012年 Tonny Xu. All rights reserved.
//

#import "CLRSTest.h"
#import "CLRSRandomGenerator.h"

@implementation CLRSTest

- (NSString *)name{
  return @"Set name in your sub class.";
}

- (NSArray *)testSet{
  NSMutableArray *testArraySet = [NSMutableArray array];
  
  [testArraySet addObject:[NSMutableArray array]];
  [testArraySet addObject:[CLRSRandomGenerator randomNumbersArrayFor:20 max:1000]];
  [testArraySet addObject:[CLRSRandomGenerator sortedNumbersArrayFor:20 order:NSOrderedAscending]];
  [testArraySet addObject:[CLRSRandomGenerator sortedNumbersArrayFor:20 order:NSOrderedDescending]];
  [testArraySet addObject:[CLRSRandomGenerator groupedNumbersArrayFor:4 groupCount:5]];
  
  return testArraySet;
}



- (void)test{
  NSLog(@"\n"
        "****************************************\n"
        "  %@\n"
        "****************************************\n", self.name);
}

- (void)prettyPrint:(NSArray *)array{
  if (nil == array || array.count == 0) {
    NSLog(@"array is empty");
    return;
  }
  
  printf("[");
  [array enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL *stop) {
    printf("%s", [[obj description] UTF8String]);
    if (idx < (array.count-1)) {
      printf(" , ");
    }
  }];
  printf("]\n");
}


@end
