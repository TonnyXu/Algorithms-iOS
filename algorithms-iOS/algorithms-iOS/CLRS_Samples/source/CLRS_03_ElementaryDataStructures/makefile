list: clean CLRS_List.c CLRS_List_Test.c
	clang -c -I../../include/ -std=c99 CLRS_List.c -o CLRS_List.o
	clang -c -I../../include/ -std=c99 CLRS_List_Test.c -o CLRS_List_Test.o
	clang CLRS_List.o CLRS_List_Test.o -o CLRS

clean: 
	rm -rf *.o CLRS

