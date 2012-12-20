//
//  CLRSSortProtocol.h
//  AlgorithmObjC
//
//  Created by 徐 廷 on 2012/12/20.
//  Copyright (c) 2012年 Tonny Xu. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol CLRSSortProtocol <NSObject>

@required
+ (void)sort:(NSMutableArray *)data comparator:(NSComparator)comparator;


@end
