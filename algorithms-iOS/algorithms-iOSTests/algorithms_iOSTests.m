//
//  algorithms_iOSTests.m
//  algorithms-iOSTests
//
//  Created by Tonny Xu on 12/01/11.
//  Copyright (c) 2012 Tonny Xu. All rights reserved.
//

#import "algorithms_iOSTests.h"
#import "TXMainThreadMOC.h"
#import "ModelClasses.h"
#import "NSManagedObject+SafelySetValue.h"

@implementation algorithms_iOSTests

- (void)setUp
{
  [super setUp];
  
  // Set-up CoreData
  [TXMainThreadMOC sharedTXMainThreadMOC];
}

- (void)tearDown
{
  // Tear-down code here.
  [MainThreadMOC saveContext];
  [super tearDown];
}

- (void)test_PopulateData{
  // View https://github.com/TonnyXu/Algorithms-iOS/wiki for a detail list
  
  NSString *plistPath = [[NSBundle bundleForClass:[algorithms_iOSTests class]] pathForResource:@"AlgorithmsMasterViewData" ofType:@"plist"];
  NSArray *dataArray = [NSArray arrayWithContentsOfFile:plistPath];
  
  
  NSEntityDescription *categoryEntity = [NSEntityDescription entityForName:@"Category" inManagedObjectContext:MainThreadMOC.managedObjectContext];
  NSEntityDescription *algorithmEntity = [NSEntityDescription entityForName:@"Algorithm" inManagedObjectContext:MainThreadMOC.managedObjectContext];
  NSEntityDescription *algorithmGistEntity = [NSEntityDescription entityForName:@"AlgorithmGist" inManagedObjectContext:MainThreadMOC.managedObjectContext];
//  NSEntityDescription *visualDemoEntity = [NSEntityDescription entityForName:@"VisualDemo" inManagedObjectContext:MainThreadMOC.managedObjectContext];

  [dataArray enumerateObjectsUsingBlock:^(NSDictionary *aCategoryDict, NSUInteger idx, BOOL *stop) {
    // A category data
    Category *aCategory = [[Category alloc] initWithEntity:categoryEntity insertIntoManagedObjectContext:MainThreadMOC.managedObjectContext];
    [aCategory safelySetValuesForKeysWithDictionary:aCategoryDict];
    
    NSArray *algorithms = [aCategoryDict objectForKey:@"algorithms"];
    [algorithms enumerateObjectsUsingBlock:^(NSDictionary *anAlgorithmDict, NSUInteger idx, BOOL *stop) {
      Algorithm *anAlgorithm = [[Algorithm alloc] initWithEntity:algorithmEntity insertIntoManagedObjectContext:MainThreadMOC.managedObjectContext];
      [anAlgorithm safelySetValuesForKeysWithDictionary:anAlgorithmDict];
      
      NSDictionary *gistDict = [anAlgorithmDict objectForKey:@"gist"];
      AlgorithmGist *anAlgorithmGist = [[AlgorithmGist alloc] initWithEntity:algorithmGistEntity insertIntoManagedObjectContext:MainThreadMOC.managedObjectContext];
      [anAlgorithmGist safelySetValuesForKeysWithDictionary:gistDict];
      
      // relations
      anAlgorithm.gist = anAlgorithmGist;
      anAlgorithmGist.algorithm = anAlgorithm;
      
      anAlgorithm.category = aCategory;
      [aCategory addAlgorithmsObject:anAlgorithm];
      
    }];
    
    
  }];
  
  
  
  
}

- (void)testInsertionSort
{
  STFail(@"Insertion Sort is not prepared yet.");
}

- (void)testMergeSort
{
  STFail(@"Merge Sort is not prepared yet.");
}



@end
