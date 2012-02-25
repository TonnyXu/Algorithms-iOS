//
//  CLRS_PowerToN.c
//  algorithms-iOS
//
//  Created by Tonny Xu on 2/6/12.
//  Copyright (c) 2012 Tonny Xu. All rights reserved.
//

#include <stdio.h>
#include <sys/time.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <inttypes.h>

#import "CLRS_CommonFunctions.h"
#import "CLRS_DivideAndConquer.h"

long power(int x, int n);

#ifndef TONNY_IOS_APP
int main(int args, char** arg_v){
  
  if (args != 3) {
    printf("Usage: ./CLRS x n\n");
    return 0;
  }
  char *endptr;
  int x = strtoimax(arg_v[1], &endptr, 10);
  if (*endptr != '\0') {
    printf("Usage: ./CLRS x n\n\n");
    printf("       x need to be a number.[%s]\n", endptr);
    return 0;
  }
  int n = strtoimax(arg_v[2], &endptr, 10);
  if (*endptr != '\0') {
    printf("Usage: ./CLRS x n\n\n");
    printf("       n need to be a number.[%s]\n", endptr);
    return 0;
  }
  
  doPowerToN(x, n);
  return 0;
}
#endif

/*
 * In real world, we need to consider a lot of situations. A basic situation is
 * `x` and `exponential` can be any number with fraction. So `x` and `e` need to
 * be `double`. Here is the C stdlib's header definition:
 *
 *   double
 *   pow(double x, double y);
 */
void doPowerToN(int x, int n){
  const char* algorithmName = "X power to Y";
  printf("[%s] calculate (%d^%d) = ", algorithmName, x, n);
  
  struct timeval start;
  gettimeofday(&start, NULL);

  long result = power(x, n);
  printf("%ld\n", result);
  
  struct timeval ended;
  gettimeofday(&ended, NULL);
  struct timeval sub;
  timersub(&ended, &start, &sub);
  printf("[%s] Using %ld.%06d seconds.\n", algorithmName, sub.tv_sec, sub.tv_usec);
}

long power(int x, int n){
  
  if (n == 0) {
    return 0;
  }
  
  if (n == 1) {
    return x;
  }
  
  if (n == 2) {
    return x * x;
  }
  
  long p = power(x, n >> 1);
  if ((n % 2) == 0) {
    return p * p;
  }else {
    return p * p * x;
  }
}

