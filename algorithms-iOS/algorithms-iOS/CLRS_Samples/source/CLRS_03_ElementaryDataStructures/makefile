list: clean CLRS_List.c
	clang -c -I../../include/ -std=c99 CLRS_List.c -o CLRS_List.o

list_test: list CLRS_List_Test.c
	clang -c -I../../include/ -std=c99 CLRS_List_Test.c -o CLRS_List_Test.o
	clang CLRS_List.o CLRS_List_Test.o -o CLRS

stack: clean list CLRS_Stack.c 
	clang -c -I../../include/ -std=c99 CLRS_Stack.c -o CLRS_Stack.o

stack_test: list stack CLRS_Stack.c
	clang -c -I../../include/ -std=c99 CLRS_Stack_Test.c -o CLRS_Stack_Test.o
	clang CLRS_List.o CLRS_Stack.o CLRS_Stack_Test.o -o CLRS

queue: clean list CLRS_Queue.c 
	clang -c -I../../include/ -std=c99 CLRS_Queue.c -o CLRS_Queue.o

queue_test: list queue CLRS_Queue.c
	clang -c -I../../include/ -std=c99 CLRS_Queue_Test.c -o CLRS_Queue_Test.o
	clang CLRS_List.o CLRS_Queue.o CLRS_Queue_Test.o -o CLRS

dlist: clean CLRS_DoublyLinkedList.c
	clang -c -I../../include/ -std=c99 CLRS_DoublyLinkedList.c -o CLRS_DoublyLinkedList.o

dlist_test: dlist CLRS_DoublyLinkedList_Test.c
	clang -c -I../../include/ -std=c99 CLRS_DoublyLinkedList_Test.c -o CLRS_DoublyLinkedList_Test.o
	clang CLRS_DoublyLinkedList.o CLRS_DoublyLinkedList_Test.o -o CLRS

clean: 
	rm -f *.o CLRS

