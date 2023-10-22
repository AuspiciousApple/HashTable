/**********************
 *
 *  
 * File: linkedlist.h
 * Author: Fabio Ventura
 *
 *
 **********************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "data.h"
#include <iostream>


class LinkedList
{
    public:

        //Constructor
        LinkedList();

        //Destructor
        ~LinkedList();

        //Getters
        bool exists(int);
        bool getNode(int, Data*);
        void printList(bool = false);
        int getCount();
        void printTable();


        //Setters
        bool addNode(int, string*);
        bool deleteNode(int);
        bool clearList();


    private:
    
        Node* head;



};

#endif //LINKEDLIST_H
