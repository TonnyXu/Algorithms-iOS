commonFunctions: CLRS_CommonFunctions.h CLRS_CommonFunctions.c
	gcc -c -std=c99 CLRS_CommonFunctions.c -o CLRS_CommonFunctions.o

insertionSort: clean commonFunctions CLRS_NaiveAlgorithms.h CLRS_InsertionSort.c
	gcc -c -std=c99 CLRS_InsertionSort.c -o CLRS_InsertionSort.o
	gcc CLRS_CommonFunctions.o CLRS_InsertionSort.o -o CLRS

bubbleSort: clean commonFunctions CLRS_NaiveAlgorithms.h CLRS_BubbleSort.c
	gcc -c -std=c99 CLRS_BubbleSort.c -o CLRS_BubbleSort.o
	gcc CLRS_CommonFunctions.o CLRS_BubbleSort.o -o CLRS

mergeSort: clean commonFunctions CLRS_DivideAndConquer.h CLRS_mergeSort.c
	gcc -c -std=c99 CLRS_MergeSort.c -o CLRS_MergeSort.o
	gcc CLRS_CommonFunctions.o CLRS_MergeSort.o -o CLRS

quicksort: clean commonFunctions CLRS_DivideAndConquer.h CLRS_Quicksort.c
	gcc -c -std=c99 CLRS_Quicksort.c -o CLRS_Quicksort.o
	gcc CLRS_CommonFunctions.o CLRS_Quicksort.o -o CLRS

heapsort: clean commonFunctions CLRS_DivideAndConquer.h CLRS_Heapsort.c
	gcc -c -std=c99 CLRS_Heapsort.c -o CLRS_Heapsort.o
	gcc CLRS_CommonFunctions.o CLRS_Heapsort.o -o CLRS

clean: 
	rm -rf *o CLRS
