//
//  CLRSTest.h
//  AlgorithmsObjCTest
//
//  Created by 徐 廷 on 2012/12/18.
//  Copyright (c) 2012年 Tonny Xu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CLRSTest : NSObject

// Methods to be overridden
- (void)test;
- (NSString *)name;

// Most of the time, you don't need to override these 2 methods.
// If you want to generate your own test set, please override `- testSet` method.
- (void)prettyPrint:(NSArray *)array;
- (NSArray *)testSet;

@end
