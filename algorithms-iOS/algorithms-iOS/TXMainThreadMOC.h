//
//  TXMainThreadMOC.h
//  BaseballHD
//
//  Created by Tonny on 11/06/27.
//  Copyright 2011 genesix, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

#define MainThreadMOC [TXMainThreadMOC sharedTXMainThreadMOC]

@interface TXMainThreadMOC : NSObject 

@property (nonatomic, retain, readonly) NSManagedObjectModel *managedObjectModel;
@property (nonatomic, retain, readonly) NSManagedObjectContext *managedObjectContext;
@property (nonatomic, retain, readonly) NSPersistentStoreCoordinator *persistentStoreCoordinator;

+ (TXMainThreadMOC *)sharedTXMainThreadMOC;

- (void)mergeChanges:(NSNotification *)notification;
- (void)saveContext;

// for test only. under Release build, it will be turned into an empty function
- (void)deleteStoreFileAndRecreateStore;
@end
