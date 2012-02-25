//
//  CLRS_Fibonacci_2.c
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

double calculateFibonacciAtIndexByFomula(unsigned int index);

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
  
  doFibonacci_fomula(index);
  return 0;
}
#endif


void doFibonacci_fomula(unsigned int index){
  const char* algorithmName = "Fibonacci(fomula)";
  printf("[%s] calculate fibonacci number at [%d] = ", algorithmName, index);
  
  struct timeval start;
  gettimeofday(&start, NULL);
  
  double result = calculateFibonacciAtIndexByFomula(index);
  printf("%.0f\n", result);
  
  struct timeval ended;
  gettimeofday(&ended, NULL);
  struct timeval sub;
  timersub(&ended, &start, &sub);
  printf("[%s] Using %ld.%06d seconds.\n", algorithmName, sub.tv_sec, sub.tv_usec);
}


double calculateFibonacciAtIndexByFomula(unsigned int index){
  /* Fibnacci number to 15
   * 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,  11,  12,  13,  14,  15
   *--------------------------------------------------------------------------- 
   * 0   1   1   2   3   5   8  13  21  34   55   89  144  233  377  610
   */
  
  /*
   * Fibnacci number at index i = ceil((golden ratio)^i/sqrt(5) + 0.5))
   * where golden ratio = (1 + sqrt(5))/2
   */
  
  if (index == 0) {
    return 0.;
  }else if (index == 1 || index == 2){
    return 1.;
  }
  
  double goldenRatio = (1 + sqrt(5.))/2;
  double resultBeforeCeil = pow(goldenRatio, index)/sqrt(5.0) + 0.5;
  printf("|_%.3f_| => ", resultBeforeCeil);
  /*
   The result is correct before fib(70)
   */
  double result = floor(resultBeforeCeil);
  
  return result;
}

/*
 Reference, calculate a fibonacci number by using fomula is not safe. Here is 
 a brief list of the correct answers from 0 to 100.
 
 Some significant moment,
 0 : 0
 1 : 1
 2 : 1
 3 : 2
 4 : 3
 5 : 5
 6 : 8
 7 : 13
 8 : 21
 9 : 34
 10 : 55
 11 : 89
 12 : 144
 13 : 233
 14 : 377
 15 : 610
 16 : 987
 17 : 1597
 18 : 2584
 19 : 4181
 20 : 6765
 21 : 10946
 22 : 17711
 23 : 28657
 24 : 46368
 25 : 75025
 26 : 121393
 27 : 196418
 28 : 317811
 29 : 514229
 30 : 832040
 31 : 1346269
 32 : 2178309
 33 : 3524578
 34 : 5702887
 35 : 9227465
 36 : 14930352
 37 : 24157817
 38 : 39088169
 39 : 63245986
 40 : 102334155
 41 : 165580141
 42 : 267914296
 43 : 433494437
 44 : 701408733
 45 : 1134903170
 46 : 1836311903
 INT32_MAX: 2147483647
 47 :       2971215073
 UINT32_MAX:4294967295
 48 :       4807526976
 49 : 7778742049
 50 : 12586269025
 51 : 20365011074
 52 : 32951280099
 53 : 53316291173
 54 : 86267571272
 55 : 139583862445
 56 : 225851433717
 57 : 365435296162
 58 : 591286729879
 59 : 956722026041
 60 : 1548008755920
 61 : 2504730781961
 62 : 4052739537881
 63 : 6557470319842
 64 : 10610209857723
 65 : 17167680177565
 66 : 27777890035288
 67 : 44945570212853
 68 : 72723460248141
 69 : 117669030460994
 70 : 190392490709135
 71 : 308061521170129
 72 : 498454011879264
 73 : 806515533049393
 74 : 1304969544928657
 75 : 2111485077978050
 76 : 3416454622906707
 77 : 5527939700884757
 78 : 8944394323791464
 79 : 14472334024676221
 80 : 23416728348467685
 81 : 37889062373143906
 82 : 61305790721611591
 83 : 99194853094755497
 84 : 160500643816367088
 85 : 259695496911122585
 86 : 420196140727489673
 87 : 679891637638612258
 88 : 1100087778366101931
 89 : 1779979416004714189
 90 : 2880067194370816120
 91 : 4660046610375530309
 92 :       7540113804746346429
 INT64_MAX: 9223372036854775807
 93 : 12200160415121876738
 UINT64_MAX:18446744073709551615
 94 :       19740274219868223167
 95 : 31940434634990099905
 96 : 51680708854858323072
 97 : 83621143489848422977
 98 : 135301852344706746049
 99 : 218922995834555169026
 100 : 354224848179261915075

 URL: http://www.maths.surrey.ac.uk/hosted-sites/R.Knott/Fibonacci/fibtable.html
 */

