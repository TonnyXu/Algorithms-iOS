//
//  CLRSRandomGenerator.h
//  AlgorithmObjC
//
//  Created by Tonny Xu on 12/17/12.
//  Copyright (c) 2012 Tonny Xu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CLRSRandomGenerator : NSObject

+ (NSMutableArray *)randomNumbersArrayFor:(NSUInteger)numberOfElement max:(NSUInteger)maxValue;
+ (NSMutableArray *)sortedNumbersArrayFor:(NSUInteger)numberOfElement order:(NSComparisonResult)order;
+ (NSMutableArray *)groupedNumbersArrayFor:(NSUInteger)numberOfEachGroup groupCount:(NSUInteger)groupCount;
@end
