//
//  CLRS_MatrxMultiplication.c
//  algorithms-iOS
//
//  Created by Tonny Xu on 2/6/12.
//  Copyright (c) 2012 Tonny Xu. All rights reserved.
//

#include <stdio.h>
#include <sys/time.h>
#include <limits.h>
#include <math.h>
#include <assert.h>

#import "CLRS_CommonFunctions.h"
#import "CLRS_NaiveAlgorithms.h"

void printMatrix(int array[], int arrayLength, unsigned char matrixSize);

#ifndef TONNY_IOS_APP
int main(void){
  
  doMatrixMultiplication(3);
  return 0;
}
#endif


void doMatrixMultiplication(unsigned char matrixSize){
  int matrixArrayLength = matrixSize * matrixSize;
  
  int matrixA[matrixArrayLength];
  generateInt32Array(matrixA, matrixArrayLength, 1, 4);
  printMatrix(matrixA, matrixArrayLength, matrixSize);
  
  int matrixB[matrixArrayLength];
  generateInt32Array(matrixB, matrixArrayLength, 1, 4);
  printMatrix(matrixB, matrixArrayLength, matrixSize);
  
  int resultArray[matrixArrayLength];
  /*
   |A00, A01, A02|   |B00, B01, B02|   |C00, C01, C02|
   |A10, A11, A12| * |B10, B11, B12| = |C10, C11, C12|
   |A20, A21, A22|   |B20, B21, B22|   |C20, C21, C22|
   
   Cxy = C00, C01,....
   
   C00 = A00*B00 + A01*B10 + A02*B20;
   C01 = A00*B01 + A01*B11 + A02*B21;
   C02 = A00*B02 + A01*B12 + A02*B22;
   
   C10 = A10*B00 + A11*B10 + A12*B20;
   C11 = A10*B01 + A11*B11 + A12*B21;
   C12 = A10*B02 + A11*B12 + A12*B22;
   
   C20 = A20*B00 + A21*B10 + A22*B20;
   C21 = A20*B01 + A21*B11 + A22*B21;
   C22 = A20*B02 + A21*B12 + A22*B22;
   
   */

  for (int cx = 0; cx < matrixSize; cx++) {
    for (int cy = 0; cy < matrixSize; cy++) {
      int cvalue = 0;
      for (int bj = 0; bj < matrixSize; bj++) {
        cvalue += matrixA[cx*matrixSize + bj] * matrixB[cy + matrixSize*bj];
      }
      resultArray[cx*matrixSize + cy] = cvalue;
    }
  }
  
  printMatrix(resultArray, matrixArrayLength, matrixSize);
  
}

void printMatrix(int array[], int arrayLength, unsigned char matrixSize){
  assert(arrayLength == matrixSize * matrixSize);
  
  for (int i = 0; i < arrayLength; i++) {
    if (i == 0) {
      printf("{{");
    }
    if (i == (arrayLength - 1)) {
      printf("%3d}}", array[i]);
    }else if (i > 0 && ((i+1) % matrixSize) == 0) {
      printf("%3d},{", array[i]);
    }else{
      printf("%3d, ", array[i]);
    }
  }
  printf("\n-----------------------------\ngoto:http://www.wolframalpha.com/ to verify the result\n");
}
