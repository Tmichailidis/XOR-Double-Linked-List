//
//  main.cpp
//  XORlist
//
//  Copyright (c) 2015 Theodore Michailidis. All rights reserved.
//

#include <cstdlib>
#include <ctime>
#include <climits>
#include "XORList.hpp"
#include "XORSortedList.hpp"

int main(int argc, const char * argv[]) { //argv[1] -> number of elements for insertion, argv[2] -> limit of the elements
    XORSortedlist<int> list;
    std::srand((unsigned int)std::time(NULL));
    int elem_num = std::atoi(argv[1]),i,limit,elem;
    if (argc == 3) //if argv[2] is set
        limit = std::atoi(argv[2]);
    else
        limit = INT_MAX;
    for (i = 0;i < elem_num;i++)
        list.insert(std::rand()%limit);
    std::cout << "List after insertion of the elements" << std:: endl;
    list.print(0);
    list.print(1);
    std::cout << "Enter a number for deletion: ";
    std::cin >> elem;
    list.deleteElem(elem);
    std::cout << "List after deletion of " << elem << std:: endl;
    list.print(0);
    list.print(1);
    list.deleteAll();
    std::cout << "Exiting!" << std::endl;
    return 0;
}
