//
//  XORSortedList.h
//  XORList
//
//  Copyright (c) 2015 Theodore Michailidis. All rights reserved.
//

#ifndef XORList_XORSortedList_h
#define XORList_XORSortedList_h

#include <iostream>
#include <stdint.h>

template <class T>
class XORSortedlist
{
    typedef struct Node{
        T elem;
        Node * ptr;
    }Node;
    
public:
    
    Node * start = NULL, *end = NULL;
    
    void insert(T newElem) //insert an element in the sorted list
    {
        Node * prev = NULL,*cur = start,* tmp,*next,*newNode;
        
        newNode = new Node;
        newNode->elem = newElem;
        if (!start || start->elem >= newElem) //empty List
        {
            newNode->ptr = start;
            if (!start)
                end = newNode;
            else
                start->ptr = (Node *) ((uintptr_t)start->ptr ^ (uintptr_t)newNode);
            start = newNode;
            return;
        }
        next = cur->ptr;    // XOR is not needed,prev = NULL
        while(next && next->elem < newElem)
        {
            tmp = next;
            next = (Node *) ((uintptr_t)cur ^ (uintptr_t)next->ptr);
            prev = cur;
            cur = tmp;
        }
        //(A XOR B) XOR B XOR C = A XOR B
        cur->ptr = (Node *)((uintptr_t)cur->ptr^(uintptr_t)next^(uintptr_t)newNode); //replacing "next" with "newNode"
        newNode->ptr = (Node *)((uintptr_t)cur^(uintptr_t)next);
        if (next)
            next->ptr = (Node *)((uintptr_t)next->ptr^(uintptr_t)cur^(uintptr_t)newNode); //replacing "cur" with "newNode"
        else
            end = newNode;
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
        if (!direction) //direction = 0
        {
            std::cout << std::endl << "Printing from start to end" << std::endl;
            prev = start;
            cur = start->ptr;
            std::cout << "List: " << start->elem;
        }
        else //direction = 1
        {
            std::cout << std::endl << "Printing from end to start" << std::endl;
            prev = end;
            cur = end->ptr;
            std::cout << "List: " << end->elem;
        }
        while(cur) //iterating through list
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
        
        while(start->ptr)
        {
            tmp = start;
            start->ptr->ptr = (Node *) ((uintptr_t)start->ptr->ptr ^ (uintptr_t)start);
            start = start->ptr;
            delete tmp;
        }
        delete end;
        start = end = NULL;
    }
    
    
    void deleteElem(T elem) //deleting all instances of given element
    {
        if (!start)
        {
            std::cout << "XOR list is empty" << std::endl;
            return;
        }
        Node * prev = NULL,*cur = start,* tmp, *next;
        while(cur && cur->elem < elem)
        {
            tmp = (Node *) ((uintptr_t)cur->ptr ^ (uintptr_t)prev);
            prev = cur;
            cur = tmp;
        }
        if (!cur || cur->elem != elem)
        {
            std::cout << elem << " is not element of the list!" <<std::endl;
            return;
        }
        next = (Node *) ((uintptr_t)cur->ptr ^ (uintptr_t)prev);
        if (prev) //preparing for the change in prev->ptr
            prev->ptr = (Node *)((uintptr_t)prev->ptr^(uintptr_t)cur);
        while(next && next->elem == elem)
        {
            tmp = cur;
            cur = next;
            next = (Node *) ((uintptr_t)next->ptr ^ (uintptr_t)tmp);
            delete(tmp);
        }
        delete cur;
        if (prev) 
            prev->ptr = (Node *)((uintptr_t)prev->ptr^(uintptr_t)next);
        else //if prev is NULL, start is modified
            start = next;
        if (next)
            next->ptr = (Node *)((uintptr_t)next->ptr^(uintptr_t)cur^(uintptr_t)prev);
        else //if next is NULL, end is modified
            end = prev;
    }
    
};


#endif
