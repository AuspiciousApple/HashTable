/*************************
* 
*
* Name: Fabio Ventura
* Coding 07
* purpose: program to serve as the method definition for the hash table class
*
*
**************************/
#include "hashtable.h"


HashTable::HashTable()
{
    table = new LinkedList[HASHTABLESIZE];
    count = 0;
}

HashTable::~HashTable()
{
    delete[] table;
}

bool HashTable::insertEntry(int id, string* data)
{
    bool success = false; //flag
    if(id > 0 && !data->empty() && data != NULL)// Validating id and string information
    {
        int index = hash(id);//hasing
        //using addnode method from linkedlist to insert entry
        success = table[index].addNode(id, data);
        if(success)
        {
            count ++;
        }
    }
    return success;
}

bool HashTable::getData(int id, string *data)
{
    bool success = false;//flag
    
    if(id > 0)// Validating data
    {
        int index = hash(id);
        // string set to getNode Data
        Data temp;
       if(table[index].getNode(id, &temp))
       {
            *data = temp.data;
            success = true;
       }
    }
    else
    {   
        //If id not valid empty string
        *data = "";
    }
    return success;
}

bool HashTable::removeEntry(int id)
{
    bool success = false;
    if(id>0)// Initial validation
    {
        int index = hash(id);
        
        if(table[index].deleteNode(id))
        {
            success = true;
            count--;

        };
    }

    return success;
}

int HashTable::getCount()
{
    return count;
}

void HashTable::printTable()
{
    for(int i = 0; i < HASHTABLESIZE; ++i)
    {
        std::cout << "Entry " << i << ": ";
        table[i].printTable(); 
        std::cout << std::endl;
    }
}

int HashTable::hash(int id)
{
    return(id % HASHTABLESIZE);
}

