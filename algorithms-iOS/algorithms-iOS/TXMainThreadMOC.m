//
//  TXMainThreadMOC.m
//  BaseballHD
//
//  Created by Tonny on 11/06/27.
//  Copyright 2011 genesix, Inc. All rights reserved.
//

#import "TXMainThreadMOC.h"
#import "TXSubThreadMOC.h"

#define DBFileName @"algorithms.sqlite"
#define momdFolderName @"algorithms_iOS.momd"
#define momFileName @"algorithms_iOS.mom"

@interface TXMainThreadMOC()

@property (nonatomic, retain, readwrite) NSManagedObjectModel *managedObjectModel;
@property (nonatomic, retain, readwrite) NSManagedObjectContext *managedObjectContext;
@property (nonatomic, retain, readwrite) NSPersistentStoreCoordinator *persistentStoreCoordinator;

- (NSURL *)applicationDocumentsDirectory;

@end

@implementation TXMainThreadMOC

@synthesize managedObjectModel;
@synthesize managedObjectContext;
@synthesize persistentStoreCoordinator;

+ (TXMainThreadMOC *)sharedTXMainThreadMOC{
  static TXMainThreadMOC *sharedInstance = nil;
  static dispatch_once_t onceToken;
  dispatch_once(&onceToken, ^{
    sharedInstance = [[TXMainThreadMOC alloc] init];
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
  NSString *bundlePath = [[NSBundle bundleForClass:[TXMainThreadMOC class]] bundlePath];
  NSString *momFilePath = [bundlePath stringByAppendingPathComponent:[NSString stringWithFormat:@"%@/%@" ,momdFolderName , momFileName]];
  self.managedObjectModel = [[NSManagedObjectModel alloc] initWithContentsOfURL:[NSURL fileURLWithPath:momFilePath]];
#else
  self.managedObjectModel = [NSManagedObjectModel mergedModelFromBundles:nil];
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
  /* NOTE by Tonny
   * Jan 29, 2012
   * 
   * Because the OCUnit bundle does not works as `[NSBundle mainBundle]` we need
   * to use `bundleForClass` to get the correct bundle path.
   */
  NSString *bundlePath = [[NSBundle bundleForClass:[TXMainThreadMOC class]] bundlePath];
  NSString *storePath = [bundlePath stringByAppendingPathComponent:DBFileName];
#else
	NSString *storePath = [[[self applicationDocumentsDirectory] path] stringByAppendingPathComponent:DBFileName];
#endif
  
	// set up the backing store
	NSFileManager *fileManager = [NSFileManager defaultManager];
	// If the expected store doesn't exist, copy the default store.
	if (![fileManager fileExistsAtPath:storePath]) {
		NSString *defaultStorePath = [[NSBundle mainBundle] pathForResource:DBFileName ofType:nil];
		if (defaultStorePath) {
			[fileManager copyItemAtPath:defaultStorePath toPath:storePath error:NULL];
		}
	}
  
	NSURL *storeUrl = [NSURL fileURLWithPath:storePath];
  SLLog(@"Store URL: %@", storeUrl);
  
	NSError *error;
  persistentStoreCoordinator = [[NSPersistentStoreCoordinator alloc] initWithManagedObjectModel: [self managedObjectModel]];
  
  
  // This method will create the DB if it is not existed.
  if (![persistentStoreCoordinator addPersistentStoreWithType:NSSQLiteStoreType configuration:nil URL:storeUrl options:nil error:&error]) {
    
    // Typical reasons for an error here include:
    // The persistent store is not accessible
    // The schema for the persistent store is incompatible with current managed object model
    // Check the error message to determine what the actual problem was.
    //
		SLLog(@"Unresolved error %@, %@", error, [error userInfo]);
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
  NSLog(@"Main MOC merged info from sub");
#endif
  
  dispatch_sync(dispatch_get_main_queue(), ^(void) {
    [mainContext mergeChangesFromContextDidSaveNotification:notification];
  });
}

- (void)saveContext
{
  NSError *error = nil;
  NSManagedObjectContext *mainMoc = self.managedObjectContext;
  if (mainMoc != nil)
  {
    if ([mainMoc hasChanges] && ![mainMoc save:&error])
    {
      /*
       Replace this implementation with code to handle the error appropriately.
       
       abort() causes the application to generate a crash log and terminate. You should not use this function in a shipping application, although it may be useful during development. 
       */
      NSLog(@"Unresolved error %@, %@", error, [error userInfo]);
      abort();
    } 
  }
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

#pragma mark - Application's Documents directory
/**
 Returns the URL to the application's Documents directory.
 */
- (NSURL *)applicationDocumentsDirectory
{
  return [[[NSFileManager defaultManager] URLsForDirectory:NSDocumentDirectory inDomains:NSUserDomainMask] lastObject];
}

@end
