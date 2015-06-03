# XOR-Double-Linked-List

Simple implementation of an XOR double linked list of T elements -> http://en.wikipedia.org/wiki/XOR_linked_list

Class XORList with 3 functions:
- void insert(T newElem,int side); 
- void print(int direction);
- void deleteAll();

Class XORSortedList with 4 functions:
- void insert(T newElem);
- void print(int direction);
- void deleteAll();
- void deleteElem(T elem);

Additionally:
- main presenting the functions of the implemented XOR Sorted List:
- inserting {arg1} random int elements with limit = INT_MAX or {arg2} (if set)
- deleting an element 
- printing the list
- deleting all elements 

Files:
- main.cpp
- XORList.hpp
- XORSortedList.hpp
- Makefile
- README.md
