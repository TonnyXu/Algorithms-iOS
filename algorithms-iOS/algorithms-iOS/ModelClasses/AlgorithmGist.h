//
//  AlgorithmGist.h
//  algorithms-iOS
//
//  Created by Tonny Xu on 1/24/12.
//  Copyright (c) 2012 Tonny Xu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class Algorithm;

@interface AlgorithmGist : NSManagedObject

@property (nonatomic, retain) NSString * url;
@property (nonatomic, retain) NSString * briefDiscription;
@property (nonatomic, retain) Algorithm *algorithm;

@end
