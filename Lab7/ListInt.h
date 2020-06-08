#include <iostream>
#include <cassert>
using namespace std;

#ifndef LISTINT
#define LISTINT

class ListInt{
    
    private:
            int *ptr_list;   // pointer to the dynamic array 
            int capacity;    // maximum number of items in the list
            int size;        // current number of items in the list
        
    public: 
            ListInt(int new_capacity = 100); // default and specific constructor
            ListInt(const ListInt &other);   // copy constructor
            ~ListInt(); // destructor-deallocate heap memory for the list items
            
            bool is_empty() const; 
            bool is_full() const; 
            int get_size() const;
            int get_capacity() const; 
            void display() const;
             
            int insert(int new_item, int pos = 0);
            int remove(int pos); 
            // deletes an item from the list at index pos
            // returns -1 if the list is empty and it cannot delete anything
            // moves all items from pos+1 to size-1 one position towards the
            // beginning of the list, adjusts size and returns 1 
            
            void sort(); 
            
            int search(int item);
            int item_at(int pos);  
             // returns the value stored in the list at index pos.
             // assert pos < size && pos >= 0
    
};
#endif 
