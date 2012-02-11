//
//  CLRS_Fibonacci_3.c
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
#include <inttypes.h>


#import "CLRS_CommonFunctions.h"
#import "CLRS_NaiveAlgorithms.h"

void calculateFibonacciAtIndex(unsigned int array[], unsigned int index);

#ifndef TONNY_IOS_APP
int main(int args, char* arg_v[]){
  
  if (args != 2) {
    printf("Usage: ./CLRS index_of_fibonacci\n");
    return 0;
  }
  char *endptr;
  int index = strtoimax(arg_v[1], &endptr, 10);
  if (*endptr != '\0') {
    printf("Usage: ./CLRS index_of_fibonacci\n\n");
    printf("       index_of_fibonacci need to be a number.[%s]\n", endptr);
    return 0;
  }

#if defined(__LP64__) || defined(_WIN64)
  // LP64 machine, OS X or Linux
  if (index > 93) {
    printf("ERROR: fib(%d) is larger than UINT64_MAX \n", index);
    return 0;
  }
#else
  // 32-bit machine, Windows or Linux or OS X
  if (index > 47) {
    printf("ERROR: fib(%d) is larger than UINT32_MAX \n", index);
    return 0;
  }
#endif

  doFibonacci_table(index);
  return 0;
}
#endif


void doFibonacci_table(unsigned int index){
  const char* algorithmName = "Fibonacci(table)";
  printf("[%s] calculate fibonacci number at [%d] = ", algorithmName, index);
  
  struct timeval start;
  gettimeofday(&start, NULL);

  if (index == 0) {
    printf("0\n");
  }else{
    unsigned int array[index + 1];
    calculateFibonacciAtIndex(array, index);
    //TODO: need to be care of (unsigned/singed)int32/int64
    printf("%u\n", array[index]);
  }
  
  struct timeval ended;
  gettimeofday(&ended, NULL);
  struct timeval sub;
  timersub(&ended, &start, &sub);
  printf("[%s] Using %ld.%d seconds.\n", algorithmName, sub.tv_sec, sub.tv_usec);
}


void calculateFibonacciAtIndex(unsigned int array[], unsigned int index){
  /* Fibnacci number to 15
   * 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,  11,  12,  13,  14,  15
   *--------------------------------------------------------------------------- 
   * 0   1   1   2   3   5   8  13  21  34   55   89  144  233  377  610
   */
  
  array[0] = 0;
  array[1] = 1;
  array[2] = 1;
  if (index > 2) {
    for (int i = 3; i <= index; i++) {
      array[i] = array[i-1] + array[i - 2];
    }
  }
}
