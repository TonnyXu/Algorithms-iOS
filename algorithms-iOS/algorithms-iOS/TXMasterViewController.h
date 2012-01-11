//
//  TXMasterViewController.h
//  algorithms-iOS
//
//  Created by Tonny Xu on 12/01/11.
//  Copyright (c) 2012 genesix Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TXDetailViewController;

#import <CoreData/CoreData.h>

@interface TXMasterViewController : UITableViewController <NSFetchedResultsControllerDelegate>

@property (strong, nonatomic) TXDetailViewController *detailViewController;

@property (strong, nonatomic) NSFetchedResultsController *fetchedResultsController;
@property (strong, nonatomic) NSManagedObjectContext *managedObjectContext;

@end
