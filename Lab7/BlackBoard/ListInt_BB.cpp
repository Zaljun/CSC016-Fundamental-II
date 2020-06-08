// ListInt.cpp = implementation file

#include "ListInt_BB.h"
#include <cassert>
#include <iostream>
using namespace std;

// Default and specific constructors: 
// 1. Allocate memory on the heap for a list of new_capacity size 
//(default capacity = 100).
// 2. set size to 0 = empty list
// 3. set capacity to new_capacity
// Preconditions: new_capacity > 0
ListInt::ListInt(int new_capacity) // default and specific constructor
{
    assert(new_capacity >= 0);
    cout << "Default + specific constructor " << endl;
    ptr_list = new int[new_capacity]; // allocate memory on the heap 
                                      // (dynamic memory)
    size = 0;  // empty list
    capacity = new_capacity;                          
}


// Copy constructor
// 1. Allocate memory for a list of capacity equal to the other list object 
// 2. Copy each item from the other list object into the new object
// 3. Copy the values of size and capacity from other to the new list object

ListInt::ListInt(const ListInt &other)       // copy constructor
: capacity(other.capacity), size(other.size) //initializer list
{
    cout << "Copy constructor " << endl;
    // incorrect (shallow copy = two objects pointing to the same memory    
    // ptr_list = other.ptr_list;
    //1. allocate new memory for the new list object 
    ptr_list = new int[capacity];
    //2. copy all items from index 0 to size-1 into the new object
    for (int i = 0; i < size; i++)
        ptr_list[i]  = other.ptr_list[i];
}

// Destructor called by the compiler when the object is out of scope
// end of a function (when you return from a function)
ListInt::~ListInt() // destructor-deallocate heap memory for the list items
{
    cout << "Destructor" << endl;
    delete [] ptr_list; // deallocate heap memory pointed by ptr_list
}


// Insert function
// inserts a new item at index pos (default value = insert at the beginning (pos = 0))
// if the list is full function returns -1 and does not insert
// if the list is not full:
//  1. Move all items from pos to size-1 one position towards the end of the list 
// 2. Insert the new item at index pos;
// 3. adjusts size
// 4. return 0
// Preconditions: pos >= 0 and pos <= size 

// insert at the end of the list pos = size
// insert at the beginning of the list pos = 0

int ListInt::insert(int new_item, int pos)
{
    assert (pos >= 0 && pos <= size);
    if (size == capacity)
    {
        cout << "Sorry, list is full" << endl;
        return -1;  // full list, unsuccessful insert
    }
    
    // 1. move all items from
    for (int i = size-1 ; i >= pos; i--)
        ptr_list[i+1] = ptr_list[i];
    
    // 2. insert item at pos
    ptr_list[pos] = new_item;
    
    // 3. increment size
    size++;
    
    return 0;  // successful insert
}

void ListInt::display() const
{
    cout << "size = " << size << endl;
    cout << "capacity = " << capacity << endl;
    for (int i = 0 ; i < size; i++)
        cout << ptr_list[i] << ' ';
    cout << endl; 
}

