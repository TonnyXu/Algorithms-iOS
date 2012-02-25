commonFunctions: CLRS_CommonFunctions.h CLRS_CommonFunctions.c
	clang -c -std=c99 CLRS_CommonFunctions.c -o CLRS_CommonFunctions.o

fibonacciRecursion: clean commonFunctions CLRS_NaiveAlgorithms.h CLRS_Fibonacci_recursion.c
	clang -c -std=c99 CLRS_Fibonacci_recursion.c -o CLRS_Fibonacci_recursion.o
	clang CLRS_CommonFunctions.o CLRS_Fibonacci_recursion.o -o CLRS

fibonacciLoop: clean commonFunctions CLRS_NaiveAlgorithms.h CLRS_Fibonacci_loop.c
	clang -c -std=c99 CLRS_Fibonacci_loop.c -o CLRS_Fibonacci_loop.o
	clang CLRS_CommonFunctions.o CLRS_Fibonacci_loop.o -o CLRS

fibonacciFomula: clean commonFunctions CLRS_NaiveAlgorithms.h CLRS_Fibonacci_fomula.c
	clang -c -std=c99 CLRS_Fibonacci_fomula.c -o CLRS_Fibonacci_fomula.o
	clang CLRS_CommonFunctions.o CLRS_Fibonacci_fomula.o -o CLRS

fibonacciTable: clean commonFunctions CLRS_NaiveAlgorithms.h CLRS_Fibonacci_table.c
	clang -c -std=c99 CLRS_Fibonacci_table.c -o CLRS_Fibonacci_table.o
	clang CLRS_CommonFunctions.o CLRS_Fibonacci_table.o -o CLRS

fibonacciMatrix: clean commonFunctions CLRS_NaiveAlgorithms.h CLRS_Fibonacci_matrix.c
	clang -c -std=c99 CLRS_Fibonacci_matrix.c -o CLRS_Fibonacci_matrix.o
	clang CLRS_CommonFunctions.o CLRS_Fibonacci_matrix.o -o CLRS

matrixMultiplication: clean commonFunctions CLRS_NaiveAlgorithms.h CLRS_MatrixMultiplication.c
	clang -c -std=c99 CLRS_MatrixMultiplication.c -o CLRS_MatrixMultiplication.o
	clang CLRS_CommonFunctions.o CLRS_MatrixMultiplication.o -o CLRS

insertionSort: clean commonFunctions CLRS_NaiveAlgorithms.h CLRS_InsertionSort.c
	clang -c -std=c99 CLRS_InsertionSort.c -o CLRS_InsertionSort.o
	clang CLRS_CommonFunctions.o CLRS_InsertionSort.o -o CLRS

bubbleSort: clean commonFunctions CLRS_NaiveAlgorithms.h CLRS_BubbleSort.c
	clang -c -std=c99 CLRS_BubbleSort.c -o CLRS_BubbleSort.o
	clang CLRS_CommonFunctions.o CLRS_BubbleSort.o -o CLRS

power: clean commonFunctions CLRS_DivideAndConquer.h CLRS_PowerToN.c
	clang -c -std=c99 CLRS_PowerToN.c -o CLRS_PowerToN.o
	clang CLRS_CommonFunctions.o CLRS_PowerToN.o -o CLRS

mergeSort: clean commonFunctions CLRS_DivideAndConquer.h CLRS_mergeSort.c
	clang -c -std=c99 CLRS_MergeSort.c -o CLRS_MergeSort.o
	clang CLRS_CommonFunctions.o CLRS_MergeSort.o -o CLRS

quicksort: clean commonFunctions CLRS_DivideAndConquer.h CLRS_Quicksort.c
	clang -c -std=c99 CLRS_Quicksort.c -o CLRS_Quicksort.o
	clang CLRS_CommonFunctions.o CLRS_Quicksort.o -o CLRS

heapsort: clean commonFunctions CLRS_DivideAndConquer.h CLRS_Heapsort.c
	clang -c -std=c99 CLRS_Heapsort.c -o CLRS_Heapsort.o
	clang CLRS_CommonFunctions.o CLRS_Heapsort.o -o CLRS

binarySearch: clean commonFunctions CLRS_DivideAndConquer.h CLRS_BinarySearch.c
	clang -c -std=c99 CLRS_BinarySearch.c -o CLRS_BinarySearch.o
	clang CLRS_CommonFunctions.o CLRS_BinarySearch.o -o CLRS

clean: 
	rm -rf *o CLRS
