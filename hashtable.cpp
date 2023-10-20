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
}

HashTable::~HashTable()
{
    delete[] table;
}

bool HashTable::insertEntry(int id, string* data)
{
    bool success = false; //flag
    if(id > 0 && !data->empty())// Validating id and string information
    {
        //using addnode method from linkedlist to insert entry
        table->addNode(id, data);
        success = true;
        count ++;
    }
    return success;
}

bool HashTable::getData(int id, string *data)
{
    bool success = false;//flag
    Data* temp;// temp data struct to retrive info

    if(table->getNode(id, temp))// if id found
    {
        // string set to getNode Data
        *data = temp->data;
        success = true;
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
        table->deleteNode(id);
        success = true;
        count--;
    }

    return success;
}

int HashTable::getCount()
{
    return count;
}

void HashTable::printTable()
{
    
    for (int i = 0; i < HASHTABLESIZE; i++)
    {
        std::cout << "Entry: " << i + 1 << ""; 
        table[i].printList(true);
    }
}

int HashTable::hash(int id)
{
    return(id % HASHTABLESIZE);
}

