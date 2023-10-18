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
    bool success = false;
    if(id > 0 && !data->empty())// Validating id and string information
    {
        table->addNode(id, data);
        success = true;
    }
    return success;
}

bool HashTable::getData(int id, string *data)
{
    
    
}

bool HashTable::removeEntry(int id)
{

}

int HashTable::getCount()
{

}

void HashTable::printTable()
{

}

int HashTable::hash(int id)
{
    return(id % HASHTABLESIZE);
}

