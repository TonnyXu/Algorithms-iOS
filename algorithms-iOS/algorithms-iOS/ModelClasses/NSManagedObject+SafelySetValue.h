//
//  NSManagedObject+SafelySetValue.h
//  BaseballHD
//
//  Created by Tonny on 11/07/12.
//  Copyright 2011 genesix, Inc. All rights reserved.
//

#import <CoreData/CoreData.h>


@interface NSManagedObject(SafelySetValue)

- (void)safelySetValuesForKeysWithDictionary:(NSDictionary *)keyedValues;

@end
