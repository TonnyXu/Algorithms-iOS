//
//  MBHDSubThreadMOC.m
//  BaseballHD
//
//  Created by Tonny on 11/06/28.
//  Copyright 2011 genesix, Inc. All rights reserved.
//

#import "MBHDSubThreadMOC.h"
#import "MBHDMainThreadMOC.h"

@implementation MBHDSubThreadMOC

@synthesize mocInitedOnSubThread;
//@synthesize modelInitedOnSubThread;

- (NSManagedObjectContext *)mocInitedOnSubThread {
  
  NSAssert(dispatch_get_current_queue() != dispatch_get_main_queue(), @"This method should not be called from main queue");
  
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

//- (NSManagedObjectModel *)modelInitedOnSubThread{
//  return MainThreadMOC.managedObjectModel;
  
  /* NOTE By Tonny
   * -------------
   * Aug 21, 2011
   * 
   * BIG BIG BIG BIG Mistake for create Model every time!
   * 
   * NSManagedModel do NOT need thread confinement!
   * 
   * That means there is no need to create it everytime in sub thread!
   * 
   * Thus it could save a huge memory comsuption!
   * 
   * Just reuse the Main thread Model is OK.
   * 
   */

  
//  if (modelInitedOnSubThread != nil) {
//    return modelInitedOnSubThread;
//  }
//  
//  
//#ifdef LOGIC_TEST
//  /*
//   NOTE by Tonny
//   -----
//   
//   I ****hate**** Apple!
//   
//   OCTest is completely bullshit!
//   
//   Getting the path for the test bundle is as hard as claim mountain Everest!
//   We will drop the default Unit test framework in the next project.
//   
//   Thanks to SO, this post helped: http://stackoverflow.com/questions/3067015/ocunit-nsbundle
//   
//   */
//  NSString *bundlePath = [[NSBundle bundleForClass:[MBHDSubThreadMOC class]] bundlePath];
//  NSString *momFilePath = [bundlePath stringByAppendingPathComponent:@"BHD.momd/BHD.mom"];
//  modelInitedOnSubThread = [[NSManagedObjectModel alloc] initWithContentsOfURL:[NSURL fileURLWithPath:momFilePath]];
//#else
//  modelInitedOnSubThread = [[NSManagedObjectModel mergedModelFromBundles:nil] retain];    
//#endif
//  
//  return modelInitedOnSubThread;
  
//}

#if !__has_feature(objc_arc)
- (void)dealloc{
  //  [modelInitedOnSubThread release];
  [mocInitedOnSubThread release];
  [super dealloc];
}
#endif

@end
