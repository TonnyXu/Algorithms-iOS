//
//  SLTrace.h
//  SLAdingo
//
//  Created by Tonny Xu on 10/04/30.
//  Copyright 2010 adingo Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#define SLLog(s,...) [SLTrace method:__func__ lineNumber:__LINE__ format:(s),##__VA_ARGS__]

@interface SLTrace : NSObject {

}

+ (void) method:(const char*)methodName lineNumber:(int)lineNumber format:(NSString*)format, ...;
+ (void) setLogOn:(BOOL)logOn;


@end
