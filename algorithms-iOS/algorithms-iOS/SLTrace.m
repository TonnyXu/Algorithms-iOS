//
//  SLTrace.m
//  SLAdingo
//
//  Created by Tonny Xu on 10/04/30.
//  Copyright 2010 adingo Inc. All rights reserved.
//

#import "SLTrace.h"

static BOOL __SLLogOn=NO;

@implementation SLTrace

+ (void) initialize
{
	char * env=getenv("SLLogOn");
	if(strcmp(env==NULL?"":env,"NO")!=0)
		__SLLogOn=YES;
}

+ (void) method:(const char*)methodName lineNumber:(int)lineNumber format:(NSString*)format, ...;
{
	if(__SLLogOn==NO)
		return;

	va_list ap;
	NSString *print;
    
	va_start(ap,format);
	print=[[NSString alloc] initWithFormat:format arguments:ap];
	va_end(ap);

  //NSLog handles synchronization issues
	NSLog(@"%s:%d %@",methodName, lineNumber,print);
  
#if !__has_feature(objc_arc)
	[print release];
#endif
	
	return;
}

+(void)setLogOn:(BOOL)logOn
{
	__SLLogOn=logOn;
}

@end
