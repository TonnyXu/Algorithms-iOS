//
//  MBHDMainThreadMOC.m
//  BaseballHD
//
//  Created by Tonny on 11/06/27.
//  Copyright 2011 genesix, Inc. All rights reserved.
//

#import "MBHDMainThreadMOC.h"
#import "MBHDSubThreadMOC.h"

@implementation MBHDMainThreadMOC

@synthesize managedObjectModel;
@synthesize managedObjectContext;
@synthesize persistentStoreCoordinator;
//@synthesize feedbackBlock;

+ (MBHDMainThreadMOC *)sharedMBHDMainThreadMOC{
  static MBHDMainThreadMOC *sharedInstance = nil;
  static dispatch_once_t onceToken;
  dispatch_once(&onceToken, ^{
    sharedInstance = [[MBHDMainThreadMOC alloc] init];
  });
  
  return sharedInstance;
}

- (id)init{
  self = [super init];
  if (self) {
    [[NSNotificationCenter defaultCenter] 
     addObserver:self 
     selector:@selector(mergeChanges:) 
     name:NSManagedObjectContextDidSaveNotification 
     object:nil]; // it's very important to set sender object to nil in BHD. 
    /*
     NOTE by Tonny
     -------------
     
     For more information about NSNotification, please refer the document about
     this method.
     */
  }
  
  return self;
}


//////////////////////////////////////////////////////////////////////////////
// CoreData properties.

// Returns the managed object context for the application.
// If the context doesn't already exist, it is created and bound to the persistent store coordinator for the application.
//
- (NSManagedObjectContext *)managedObjectContext {
  
  if (managedObjectContext != nil) {
    return managedObjectContext;
  }
  
  NSPersistentStoreCoordinator *coordinator = [self persistentStoreCoordinator];
  if (coordinator != nil) {
    managedObjectContext = [NSManagedObjectContext new];
    [managedObjectContext setPersistentStoreCoordinator: coordinator];
    managedObjectContext.undoManager = nil;
    [managedObjectContext setMergePolicy:NSOverwriteMergePolicy];
  }
  return managedObjectContext;
}

// Returns the managed object model for the application.
// If the model doesn't already exist, it is created by merging all of the models found in the application bundle.
//
- (NSManagedObjectModel *)managedObjectModel {
  
  if (managedObjectModel != nil) {
    return managedObjectModel;
  }


#ifdef LOGIC_TEST
  /*
   NOTE by Tonny
   -----
   
   I ****hate**** Apple!
   
   OCTest is complete bullshit!
   
   Getting the path for the test bundle is as hard as claim mountain Everest!
   We will drop the default Unit test framework in the next project.
   
   Thanks to SO, this post helped: http://stackoverflow.com/questions/3067015/ocunit-nsbundle
   
   */
  NSString *bundlePath = [[NSBundle bundleForClass:[MBHDMainThreadMOC class]] bundlePath];
  NSString *momFilePath = [bundlePath stringByAppendingPathComponent:@"BHD.momd/BHD.mom"];
  managedObjectModel = [[NSManagedObjectModel alloc] initWithContentsOfURL:[NSURL fileURLWithPath:momFilePath]];
#else
#if __has_feature(objc_arc)
  managedObjectModel = [NSManagedObjectModel mergedModelFromBundles:nil];
#else
  managedObjectModel = [[NSManagedObjectModel mergedModelFromBundles:nil] retain];    
#endif
#endif
  
  return managedObjectModel;
}

// Returns the persistent store coordinator for the application.
// If the coordinator doesn't already exist, it is created and the application's store added to it
- (NSPersistentStoreCoordinator *)persistentStoreCoordinator {
  
  if (persistentStoreCoordinator != nil) {
    return persistentStoreCoordinator;
  }
  
#ifdef LOGIC_TEST
//  NSString *bundlePath = [[[NSBundle bundleForClass:[MBHDMainThreadMOC class]] pathForResource:@"4_2_star_13x13" ofType:@"png"] stringByDeletingLastPathComponent];
  NSString *bundlePath = [[NSBundle bundleForClass:[MBHDMainThreadMOC class]] bundlePath];
  NSString *storePath = [bundlePath stringByAppendingPathComponent:@"BHD.sqlite"];
#else
	NSString *storePath = @"";//[[SLApp getDocumentFolder] stringByAppendingPathComponent:@"BHD.sqlite"];
#endif
  
	// set up the backing store
	NSFileManager *fileManager = [NSFileManager defaultManager];
	// If the expected store doesn't exist, copy the default store.
	if (![fileManager fileExistsAtPath:storePath]) {
		NSString *defaultStorePath = [[NSBundle mainBundle] pathForResource:@"BHD" ofType:@"sqlite"];
		if (defaultStorePath) {
			[fileManager copyItemAtPath:defaultStorePath toPath:storePath error:NULL];
		}
	}
  
	NSURL *storeUrl = [NSURL fileURLWithPath:storePath];
//  SLLog(@"Store URL: %@", storeUrl);
  
	NSError *error;
  persistentStoreCoordinator = [[NSPersistentStoreCoordinator alloc] initWithManagedObjectModel: [self managedObjectModel]];
  
  
  // This method will create the DB if it is not existed.
  if (![persistentStoreCoordinator addPersistentStoreWithType:NSSQLiteStoreType configuration:nil URL:storeUrl options:nil error:&error]) {
    
    // Typical reasons for an error here include:
    // The persistent store is not accessible
    // The schema for the persistent store is incompatible with current managed object model
    // Check the error message to determine what the actual problem was.
    //
//		SLLog(@"Unresolved error %@, %@", error, [error userInfo]);
		abort();
  }
  return persistentStoreCoordinator;
}

// this is called via observing "NSManagedObjectContextDidSaveNotification" from SubThreadMOC
- (void)mergeChanges:(NSNotification *)notification {
  
  
	NSManagedObjectContext *mainContext = [self managedObjectContext];
  if ([notification object] == mainContext) {
    // main context save, no need to perform the merge
    return;
  }

#ifdef DEBUG
//  NSLog(@"Main MOC merged info from sub");
#endif
//  SLLog(@"\n***************************************************************\n"
//        "Got a notification from sub Moc and will merge the changes: \n"
//        "\n***************************************************************\n");
  
  dispatch_sync(dispatch_get_main_queue(), ^(void) {
    [mainContext mergeChangesFromContextDidSaveNotification:notification];
//    dispatch_async(dispatch_get_main_queue(), ^(void) {
//      if (self.feedbackBlock) {
//        feedbackBlock();
//        
//        // clean the feedback block after it it executed.
//        self.feedbackBlock = nil;
//      }
//    });
  });
}

#ifdef DEBUG
- (void)deleteStoreFileAndRecreateStore{
  NSPersistentStore *store = [[self.persistentStoreCoordinator persistentStores] lastObject];
  NSError *error;
  NSURL *storeURL = store.URL;
  NSPersistentStoreCoordinator *storeCoordinator = self.persistentStoreCoordinator;
  [storeCoordinator removePersistentStore:store error:&error];
  [[NSFileManager defaultManager] removeItemAtPath:storeURL.path error:&error];
#if !__has_feature(objc_arc)
  [persistentStoreCoordinator release];
#endif
  persistentStoreCoordinator = nil;
}
#else
- (void)deleteStoreFileAndRecreateStore{}
#endif

@end
