//
//  algorithms_iOSTests.m
//  algorithms-iOSTests
//
//  Created by Tonny Xu on 12/01/11.
//  Copyright (c) 2012 Tonny Xu. All rights reserved.
//

#import "algorithms_iOSTests.h"
#import "TXMainThreadMOC.h"

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
  
  [super tearDown];
}

- (void)testExample
{
  STFail(@"Unit tests are not implemented yet in algorithms-iOSTests");
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
