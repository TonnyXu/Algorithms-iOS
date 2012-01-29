//
//  Algorithm.h
//  algorithms-iOS
//
//  Created by Tonny Xu on 1/24/12.
//  Copyright (c) 2012 Tonny Xu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class AlgorithmGist;

@interface Algorithm : NSManagedObject

@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSNumber * hasVisualDemo;
@property (nonatomic, retain) NSManagedObject *category;
@property (nonatomic, retain) AlgorithmGist *gist;

@end
