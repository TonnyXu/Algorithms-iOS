//
//  main.m
//  AlgorithmsObjCTest
//
//  Created by 徐 廷 on 2012/12/18.
//  Copyright (c) 2012年 Tonny Xu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CLRSTestHeapSort.h"
#import "CLRSTestQuickSort.h"
#import "CLRSTestMergeSort.h"
#import "CLRSTestCountingSort.h"

int main(int argc, const char * argv[])
{
  
  @autoreleasepool {
    NSArray *testClasses = @[@"CLRSTestHeapSort", @"CLRSTestQuickSort", @"CLRSTestMergeSort", @"CLRSTestCountingSort", @"CLRSTestRadixSort"];
    
    [testClasses enumerateObjectsUsingBlock:^(NSString *className, NSUInteger idx, BOOL *stop) {
      CLRSTest *testClassInstance = [NSClassFromString(className) new];
      [testClassInstance test];
    }];
  }
  return 0;
}

