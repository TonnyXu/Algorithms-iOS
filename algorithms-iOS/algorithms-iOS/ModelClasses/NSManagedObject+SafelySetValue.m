//
//  NSManagedObject+SafelySetValue.m
//  BaseballHD
//
//  Created by Tonny on 11/07/12.
//  Copyright 2011 genesix, Inc. All rights reserved.
//

#import "NSManagedObject+SafelySetValue.h"


@implementation NSManagedObject(SafelySetValue)

- (void)safelySetValuesForKeysWithDictionary:(NSDictionary *)keyedValues
{
  NSDictionary *attributes = [[self entity] attributesByName];
  for (NSString *attribute in attributes) {
    id value = [keyedValues objectForKey:attribute];
    if (value == nil || (value == [NSNull null]) || [value isKindOfClass:[NSDictionary class]] || [value isKindOfClass:[NSArray class]]) {
      // Don't attempt to set nil, or you'll overwite values in self that aren't present in keyedValues
      continue;
    }
    
    NSAttributeType attributeType = [[attributes objectForKey:attribute] attributeType];
    
    /* incompatible type */
    if ((attributeType == NSStringAttributeType) && ([value isKindOfClass:[NSNumber class]])) {
      value = [value stringValue];
    } else if (((attributeType == NSInteger16AttributeType) || (attributeType == NSInteger32AttributeType) || (attributeType == NSInteger64AttributeType) || (attributeType == NSBooleanAttributeType)) && ([value isKindOfClass:[NSString class]])) {
      value = [NSNumber numberWithInteger:[value  integerValue]];
    } else if ((attributeType == NSFloatAttributeType) && ([value isKindOfClass:[NSString class]])) {
      value = [NSNumber numberWithDouble:[value doubleValue]];
    }
    
    [self setValue:value forKey:attribute];
  }
}
@end

