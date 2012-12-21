//
//  CLRSTest.m
//  AlgorithmsObjCTest
//
//  Created by 徐 廷 on 2012/12/18.
//  Copyright (c) 2012年 Tonny Xu. All rights reserved.
//

#import "CLRSTest.h"

@implementation CLRSTest

- (NSString *)name{
  return @"Set name in your sub class.";
}


- (void)test{
  NSLog(@"this method is mean to be overrided by sub classes.");
  abort();
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
