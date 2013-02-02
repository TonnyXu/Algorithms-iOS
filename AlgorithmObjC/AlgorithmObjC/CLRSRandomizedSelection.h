//
//  CLRSRandomizedSelection.h
//  AlgorithmObjC
//
//  Created by Yi Gu on 1/13/13.
//  Copyright (c) 2013 Tonny Xu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CLRSRandomizedSelection : NSObject
+ (id)selectNth:(NSUInteger)n fromArray:(NSArray *)array withComparator:(NSComparator)comparator;
@end
