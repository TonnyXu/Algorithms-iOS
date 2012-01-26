//
//  MBHDMainThreadMOC.h
//  BaseballHD
//
//  Created by Tonny on 11/06/27.
//  Copyright 2011 genesix, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

#define MainThreadMOC [MBHDMainThreadMOC sharedMBHDMainThreadMOC]

//typedef void (^MBHDWaitForFinishingMergingSubMocSavingBlock)(void);

@interface MBHDMainThreadMOC : NSObject 

@property (nonatomic, retain, readonly) NSManagedObjectModel *managedObjectModel;
@property (nonatomic, retain, readonly) NSManagedObjectContext *managedObjectContext;
@property (nonatomic, retain, readonly) NSPersistentStoreCoordinator *persistentStoreCoordinator;

/* NOTE by Tonny
 * July 25, 2011
 * -------------
 * 
 * Here, using feedbackBlock to notice the original part code of main thread 
 * for new data faulting to main thread is finished.
 * 
 * A big advantage is that we can inform back to the code where need to response
 * to the saving of new data. Such kind of response might not be use the data 
 * soon enought, it could be an update to UI.
 *
 * ----
 * Update: July 25, 2011
 * This solution does not work out. so I comment it out. The reason is still 
 * unknown. Maybe because I'm doing wrong with the block object retain/release.
 * Currently, modified the methods in MBHDBusinessObjectMaster to add a support
 * a callback when finished saving.
 * 
 */
//@property (nonatomic, retain) MBHDWaitForFinishingMergingSubMocSavingBlock feedbackBlock;

+ (MBHDMainThreadMOC *)sharedMBHDMainThreadMOC;

- (void)mergeChanges:(NSNotification *)notification;

// for test only. under Release build, it will be turned into an empty function
- (void)deleteStoreFileAndRecreateStore;
@end
