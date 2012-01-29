//
//  Category.m
//  algorithms-iOS
//
//  Created by Tonny Xu on 1/30/12.
//  Copyright (c) 2012 Tonny Xu. All rights reserved.
//

#import "Category.h"
#import "Algorithm.h"


@implementation Category

@dynamic name;
@dynamic shortDiscription;
@dynamic algorithms;

- (void)addAlgorithmsObject:(Algorithm *)value{
  /* NOTE by Tonny
   * Jan 30, 2012
   * 
   * After googling, this looks like a bug in CoreData/iOS5 with NSOrderedSet.
   * 
   */

  NSMutableOrderedSet* tempSet = [NSMutableOrderedSet orderedSetWithOrderedSet:self.algorithms];
  [tempSet addObject:value];
  self.algorithms = tempSet;
}
@end
