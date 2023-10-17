/**********************
 *
 *  
 * File: hashtable.h
 * Author: Fabio Ventura
 *
 *
 **********************/
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream> //For loose coupling, so string does not rely on linkedlist.h
#include "linkedlist.h"

class HashTable
{
    public:
        //Constructors
        HashTable();

        //Destructors
        ~HashTable();

        //Getters
        int getCount();
        bool getData(int, string*);
        void printTable();

        //Setters
        bool removeEntry(int);
        bool insertEntry(int, string*);


    private:
        //Hash method, uses modulo
        int hash(int); 

        //Attributes
        int count;
};

#endif // HASHTABLE_H