//
//  TXAppDelegate.m
//  algorithms-iOS
//
//  Created by Tonny Xu on 12/01/11.
//  Copyright (c) 2012 Tonny Xu. All rights reserved.
//

#import "TXAppDelegate.h"
#import "TXMainThreadMOC.h"
#import "CLRS_InsertionSort.h"

#import "TXMasterViewController.h"

@implementation TXAppDelegate

@synthesize window = _window;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
  doInsertionSort(100000);
  
    // Override point for customization after application launch.
  if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad) {
      UISplitViewController *splitViewController = (UISplitViewController *)self.window.rootViewController;
      UINavigationController *navigationController = [splitViewController.viewControllers lastObject];
      splitViewController.delegate = (id)navigationController.topViewController;
      
      UINavigationController *masterNavigationController = [splitViewController.viewControllers objectAtIndex:0];
      TXMasterViewController *controller = (TXMasterViewController *)masterNavigationController.topViewController;
      controller.managedObjectContext = MainThreadMOC.managedObjectContext;
  } else {
      UINavigationController *navigationController = (UINavigationController *)self.window.rootViewController;
      TXMasterViewController *controller = (TXMasterViewController *)navigationController.topViewController;
      controller.managedObjectContext = MainThreadMOC.managedObjectContext;
  }
    return YES;
}
							
- (void)applicationWillResignActive:(UIApplication *)application
{
  /*
   Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
   Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
   */
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
  /*
   Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
   If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
   */
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
  /*
   Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
   */
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
  /*
   Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
   */
}

- (void)applicationWillTerminate:(UIApplication *)application
{
  // Saves changes in the application's managed object context before the application terminates.
//  [self saveContext];
  [MainThreadMOC saveContext];
}


@end
