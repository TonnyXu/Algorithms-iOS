all: CLRS

CLRS: commonFunctions naiveAlgorithms
	gcc CLRS_InsertionSort.o CLRS_CommonFunctions.o -o CLRS

commonFunctions: CLRS_CommonFunctions.h CLRS_CommonFunctions.c
	gcc -c -std=c99 CLRS_CommonFunctions.c -o CLRS_CommonFunctions.o

naiveAlgorithms: CLRS_InsertionSort.h CLRS_InsertionSort.c
	gcc -c -std=c99 CLRS_InsertionSort.c -o CLRS_InsertionSort.o

clean: 
	rm -rf *o CLRS
