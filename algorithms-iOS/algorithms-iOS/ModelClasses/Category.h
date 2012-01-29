//
//  Category.h
//  algorithms-iOS
//
//  Created by Tonny Xu on 1/30/12.
//  Copyright (c) 2012 Tonny Xu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class Algorithm;

@interface Category : NSManagedObject

@property (nonatomic, retain) NSString * name;
@property (nonatomic, retain) NSString * shortDiscription;
@property (nonatomic, retain) NSOrderedSet *algorithms;
@end

@interface Category (CoreDataGeneratedAccessors)

- (void)insertObject:(Algorithm *)value inAlgorithmsAtIndex:(NSUInteger)idx;
- (void)removeObjectFromAlgorithmsAtIndex:(NSUInteger)idx;
- (void)insertAlgorithms:(NSArray *)value atIndexes:(NSIndexSet *)indexes;
- (void)removeAlgorithmsAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInAlgorithmsAtIndex:(NSUInteger)idx withObject:(Algorithm *)value;
- (void)replaceAlgorithmsAtIndexes:(NSIndexSet *)indexes withAlgorithms:(NSArray *)values;
- (void)addAlgorithmsObject:(Algorithm *)value;
- (void)removeAlgorithmsObject:(Algorithm *)value;
- (void)addAlgorithms:(NSOrderedSet *)values;
- (void)removeAlgorithms:(NSOrderedSet *)values;
@end
