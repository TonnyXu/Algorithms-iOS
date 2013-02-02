//
//  CLRSList.h
//  AlgorithmObjC
//
//  Created by Yi Gu on 1/19/13.
//  Copyright (c) 2013 Tonny Xu. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol CLRSList <NSObject>
@required
- (id)search:(id)object;
- (void)insert:(id)object;
- (void)remove:(id)object;
@end

