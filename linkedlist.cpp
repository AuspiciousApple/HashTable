/*************************
* 
*
* Name: Fabio Ventura
* Coding 06
* purpose: program to serve as the driver file for testing the Linked-List ADT
*
*
**************************/

#include "linkedlist.h"


LinkedList::LinkedList()
{
    this->head = NULL;
}

LinkedList::~LinkedList(){}

bool LinkedList::addNode(int id, string* data)
{
    bool success = false;  //Flag

    // Initial validation
    if (id > 0 && data != NULL && !data->empty())
    {
        Node *current = head; //Initializing current
        Node *prev = NULL;

        while (current != NULL && (id > current->data.id))//Used to iterate through the list
        {
            prev = current;
            current = current->next;
        }

        if (current == NULL || id != current->data.id) // Ensure we didn't exit due to a duplicate id
        {
            Node *newNode = new Node;
            newNode->data.id = id;
            newNode->data.data = *data;

            
            if (prev == NULL) // Insert at the beginning
            {
                if(head != NULL) // If there's an existing head
                head->prev = newNode;
                newNode->next = head;
                newNode->prev = NULL;
                head = newNode;
            }
            else if(current == NULL) // Insert at the end
            {
                newNode->next = NULL;
                newNode->prev = prev;
                prev->next = newNode;
            }
            else // Insert in the middle
            {
                newNode->next = current;
                newNode->prev = prev;
                prev->next = newNode;
                current->prev = newNode;
            }

            success = true;
        }
    }

    return success;
}

bool LinkedList::deleteNode(int id)
{
    bool success = false;  //Flag

    // Initial validation
    if (id > 0)
    {
        Node *current = head; //Initializing Head
        Node *prev = NULL;

        while(current != NULL && id != current->data.id) // Used to iterate through the list
        {
            prev = current;
            current = current->next;
        }

        if (current != NULL && id == current->data.id)
        {
            if (prev == NULL) //Delete at Head
            {
                head = current->next;
                if (head)
                {
                    head->prev = NULL;
                }
            }
            else if(current->next == NULL) //Delete at the tail
            {
                prev->next = NULL;
            }
            else // Delete at Tail
            {
                prev->next = current->next;
                current->next->prev = prev;
            }
            delete current;
            success = true;
        }
    }
    return success;
}

bool LinkedList::getNode(int id, Data* data)
{
    bool success = false; // flag
    Node* current = head; // initialize head

    //Validating id is a legitimate value
    if(id > 0)
    {
        while(success == false && current != NULL)
        {
            if(current->data.id == id) // comparing 
            {
                *data = current->data; //returningn node found
                success = true;
            }
            else
            {
                current = current->next;
            }
            
        }
        if (!success) // If node not found standard output given
        {
            data->id = -1;
            data->data= "";

        }
    }
    return success;
    
}

void LinkedList::printList(bool backward)
{
    if(backward) //Assume true
    {
        //Find tail
        Node* current = head;
        while(current && current->next)
        {
            current = current->next;
        }
        // Traverse backward
        while(current) 
        {
            std::cout << current->data.id << ": " << current->data.data << std::endl;
            current = current->prev;
        }
    }
    else 
    {
        // Traverse forward
        Node* current = head;
        while(current) 
        {
            std::cout << current->data.id << ": " << current->data.data << std::endl;
            current = current->next;
        }
    }
}

int LinkedList::getCount()
{
    Node* current = head;
    int count = 0;

    while(current) // starting at current, ends at null tail
    {
        count++; //counter
        current = current->next;
    }
    return count;
}

bool LinkedList::clearList()
{
    Node* current = head;
    Node* temp = current;
    while(current != NULL) // go until Null is reached
    {
        current = current->next;
        delete temp;
    }
    head = NULL; // set head to NULL
    return true;
}

bool LinkedList::exists(int id)
{
    bool exist = false; //flag
    Node* current = head;
    
    while(exist == false && current != NULL) // conditions for exists
    {
        if(current->data.id == id) // if id found
        {
            exist = true;
        }
        else
        {
            current = current->next;
        }
        
    }
    //output
    return exist;
}



