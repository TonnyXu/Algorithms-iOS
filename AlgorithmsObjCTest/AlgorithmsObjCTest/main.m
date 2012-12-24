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

int main(int argc, const char * argv[])
{
  
  @autoreleasepool {
    CLRSTestHeapSort *testingHeapSort = [CLRSTestHeapSort new];
    [testingHeapSort test];
    
    CLRSTestQuickSort *testingQuickSort = [CLRSTestQuickSort new];
    [testingQuickSort test];
    
    CLRSTestMergeSort *testingMergeSort = [CLRSTestMergeSort new];
    [testingMergeSort test];
    
  }
  return 0;
}

