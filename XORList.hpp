//
//  XORList.h
//  XORList
//
//  Copyright (c) 2015 Theodore Michailidis. All rights reserved.
//

#ifndef __XORList__XORList__
#define __XORList__XORList__

#include <iostream>
#include <stdint.h>

template <class T>
class XORlist
{
    typedef struct Node{
        T elem;
        Node * ptr;
    }Node;
    
public:
    
    Node * start = NULL, *end = NULL;
    
    void insert(T newElem,int side) //insert elements in the list from either sides. side -> 0: start,1: end
    {
        if (side != 0 && side != 1)
        {
            std::cout << "Wrong direction option! Try again" << std::endl;
            return;
        }
        if (!start) //empty List
        {
            start = new Node;
            start->elem = newElem;
            start->ptr = NULL;
            end = start;
        }
        else
        {
            Node * tmp = new Node;
            tmp->elem = newElem;
            if (!side) //start
            {
                std::cout << "Inserting " << newElem << " at start" << std::endl;
                tmp->ptr = start;
                start->ptr = (Node *)((uintptr_t)start->ptr^(uintptr_t)tmp);
                start = tmp;
            }
            else //end
            {
                std::cout << "Inserting " << newElem << " at end" << std::endl;
                tmp->ptr = end;
                end->ptr = (Node *)((uintptr_t)end->ptr^(uintptr_t)tmp);
                end = tmp;
            }
        }
    }
    
    void print(int direction) //printing list from any direction. direction -> 0: forth, 1: back
    {
        if (direction != 0 && direction != 1)
        {
            std::cout << "Wrong direction option! Try again" << std::endl;
            return;
        }
        if (!start)
        {
            std::cout << "XOR list is empty" << std::endl;
            return;
        }
        Node * prev,*cur,* tmp;
        if (!direction)
        {
            std::cout << std::endl << "Printing from start to end" << std::endl;
            prev = start;
            cur = start->ptr;
            std::cout << "List: " << start->elem;
        }
        else
        {
            std::cout << std::endl << "Printing from end to start" << std::endl;
            prev = end;
            cur = end->ptr;
            std::cout << "List: " << end->elem;
        }
        while(cur)
        {
            std::cout << " <-> " << cur->elem;
            tmp = (Node *) ((uintptr_t)cur->ptr ^ (uintptr_t)prev);
            prev = cur;
            cur = tmp;
        }
        std::cout<<std::endl<<std::endl;
    }
    
    void deleteAll() //delete all elements of the list
    {
        Node * tmp;
        int i= 1;
        while(start->ptr)
        {
            i++;
            tmp = start;
            std::cout << "Deleting " << tmp->elem << std::endl;
            start->ptr->ptr = (Node *) ((uintptr_t)start->ptr->ptr ^ (uintptr_t)start);
            start = start->ptr;
            delete tmp;
        }
        delete end;
        start = end = NULL;
        std::cout << "Deleted " << i << " elements!" << std::endl;
        print(0);
    }
    
};




#endif /* defined(__XORList__XORList__) */
