//
//  TXSubThreadMOC.m
//  BaseballHD
//
//  Created by Tonny on 11/06/28.
//  Copyright 2011 genesix, Inc. All rights reserved.
//

#import "TXSubThreadMOC.h"
#import "TXMainThreadMOC.h"

@implementation TXSubThreadMOC

@synthesize mocInitedOnSubThread;

- (NSManagedObjectContext *)mocInitedOnSubThread {
  
  NSAssert(![NSThread isMainThread], @"This method should not be called from main queue");
  
  if (mocInitedOnSubThread != nil) {
    return mocInitedOnSubThread;
  }
  
  NSPersistentStoreCoordinator *coordinator = [MainThreadMOC persistentStoreCoordinator];
  if (coordinator != nil) {
    mocInitedOnSubThread = [NSManagedObjectContext new];
    [mocInitedOnSubThread setPersistentStoreCoordinator: coordinator];
    mocInitedOnSubThread.undoManager = nil;
  }
  return mocInitedOnSubThread;
}

#if !__has_feature(objc_arc)
- (void)dealloc{
  [mocInitedOnSubThread release];
  [super dealloc];
}
#endif

@end
