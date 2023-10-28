/*************************
* 
*
* Name: Fabio Ventura
* Coding 07
* purpose: program to serve as the driver file for the program
*
*
**************************/

#include "main.h"

int main(int argc, char** argv) 
{
    //seed the rand function
    srand(time(NULL));

    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) 
    {
        ids[i] = rand() % HASHTABLESIZE + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) 
        {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    // Show Test Data 

    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) 
    {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    cout << "Creating hash table..." << endl;
    HashTable hashtable;

    hashtable.getCount();
     // Inserting entries
    cout << "\nInserting entries..." << endl;
    for (int i = 1; i <= HASHTABLESIZE; ++i) 
    {
        string* data = new string("Data" + std::to_string(i));
        bool success = hashtable.insertEntry(i, data);
        cout << "Inserting ID " << i << ": " << (success ? "Success" : "Failed") << endl;
    }
    
    for (int i = 0; i < testdatasize; ++i) 
    {
        bool success = hashtable.insertEntry(ids[i], &strs[i]);
        cout << "Inserting ID " << ids[i] << ": " << (success ? "Success" : "Failed") << endl;
    }

    // Attempting to insert duplicate
    cout << "\nAttempting to insert duplicate entry..." << endl;
    string* duplicateData = new string("Data1");
    bool success = hashtable.insertEntry(1, duplicateData);
    cout << "Inserting ID 1 again: " << (success ? "Success" : "Failed") << endl;

    // Getting data
    cout << "\nGetting data..." << endl;
    string data;
    for (int i = 1; i <= HASHTABLESIZE; ++i) 
    {
        if (hashtable.getData(i, &data)) 
        {
            cout << "Data for ID " << i << ": " << data << endl;
        } else 
        {
            cout << "Failed to get data for ID " << i << endl;
        }
    }

    // Getting data for non-existent entry
    cout << "\nGetting data for non-existent entry..." << endl;
    if (hashtable.getData(HASHTABLESIZE + 1, &data)) 
    {
        cout << "Data for ID " << HASHTABLESIZE + 1 << ": " << data << endl;
    } 
    else 
    {
        cout << "Failed to get data for ID " << HASHTABLESIZE + 1 << endl;
    }
    cout << "\nPrinting the table..." << endl;
    hashtable.printTable();

    // Removing entries
    cout << "\nRemoving entries..." << endl;
    for (int i = 1; i <= HASHTABLESIZE; ++i) 
    {
        bool success = hashtable.removeEntry(i);
        cout << "Removing ID " << i << ": " << (success ? "Success" : "Failed") << endl;
    }

    // Removing non-existent entry
    cout << "\nRemoving non-existent entry..." << endl;
    success = hashtable.removeEntry(HASHTABLESIZE + 1);
    cout << "Removing ID " << HASHTABLESIZE + 1 << ": " << (success ? "Success" : "Failed") << endl;

    // Printing the table
    cout << "\nPrinting the table..." << endl;
    hashtable.printTable();   

    // 1. Test Insertion using the original strings
    std::cout << "Testing Insertion with original strings:" << std::endl;
    for (int i = 0; i < testdatasize; ++i) 
    {
        bool success = hashtable.insertEntry(ids[i], &strs[i]);
        if (success) 
        {
            std::cout << "Inserted: " << ids[i] << " -> " << strs[i] << std::endl;
        } else 
        {
            std::cout << "Failed to insert: " << ids[i] << " -> " << strs[i] << std::endl;
        }
    }

    // 2. Test Data Retrieval
    std::cout << "\nTesting Data Retrieval:" << std::endl;
    for (int i = 0; i < testdatasize; ++i) 
    {
        std::string data;
        bool success = hashtable.getData(ids[i], &data);
        if (success) 
        {
            std::cout << "Retrieved: " << ids[i] << " -> " << data << std::endl;
        } else 
        {
            std::cout << "Failed to retrieve data for ID: " << ids[i] << std::endl;
        }
    }

    // 3. Test Removal
    std::cout << "\nTesting Removal:" << std::endl;
    for (int i = 0; i < testdatasize; i += 3) 
    { // Remove every 3rd entry
        bool success = hashtable.removeEntry(ids[i]);
        if (success) 
        {
            std::cout << "Removed entry with ID: " << ids[i] << std::endl;
        } else 
        {
            std::cout << "Failed to remove entry with ID: " << ids[i] << std::endl;
        }
    }

    // 4. Test Print Table
    std::cout << "\nPrinting Hash Table after removals:" << std::endl;
    hashtable.printTable();

    return 0;
}