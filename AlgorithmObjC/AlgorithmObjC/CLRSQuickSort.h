//
//  CLRSQuickSort.h
//  AlgorithmObjC
//
//  Created by Tonny Xu on 12/15/12.
//  Copyright (c) 2012 Tonny Xu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CLRSQuickSort : NSObject

+ (void)sort:(NSMutableArray *)data comparator:(NSComparator)comparator;
@end
