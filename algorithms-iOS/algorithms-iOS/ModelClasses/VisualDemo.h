//
//  VisualDemo.h
//  algorithms-iOS
//
//  Created by Tonny Xu on 1/29/12.
//  Copyright (c) 2012 Tonny Xu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class Algorithm;

@interface VisualDemo : NSManagedObject

@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) Algorithm *algorithm;

@end
