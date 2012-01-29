//
//  Category.h
//  algorithms-iOS
//
//  Created by Tonny Xu on 1/24/12.
//  Copyright (c) 2012 Tonny Xu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class Algorithm;

@interface Category : NSManagedObject

@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSSet *algorithms;
@end

@interface Category (CoreDataGeneratedAccessors)

- (void)addAlgorithmsObject:(Algorithm *)value;
- (void)removeAlgorithmsObject:(Algorithm *)value;
- (void)addAlgorithms:(NSSet *)values;
- (void)removeAlgorithms:(NSSet *)values;

@end
