//
//  TXSubThreadMOC.h
//  BaseballHD
//
//  Created by Tonny on 11/06/28.
//  Copyright 2011 genesix, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>


@interface TXSubThreadMOC : NSObject 

@property (nonatomic, retain, readonly) NSManagedObjectContext *mocInitedOnSubThread;


@end
