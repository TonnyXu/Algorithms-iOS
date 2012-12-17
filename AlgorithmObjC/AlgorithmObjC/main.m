//
//  main.m
//  AlgorithmObjC
//
//  Created by Tonny Xu on 11/30/12.
//  Copyright (c) 2012 Tonny Xu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CLRSRandomGenerator.h"
#import "CLRSQuickSort.h"

int main(int argc, const char * argv[])
{
  
  @autoreleasepool {
    
    // insert code here...
    NSLog(@"Hello, World!");
    NSMutableArray *randomArray = [CLRSRandomGenerator randomNumbersArrayFor:20 max:100];
    NSLog(@"Before sort: %@", randomArray);
    [CLRSQuickSort sort:randomArray comparator:^NSComparisonResult(NSNumber *obj1, NSNumber *obj2) {
      return [obj1 compare:obj2];
    }];
    NSLog(@"After  sort: %@", randomArray);
  }
  return 0;
}

