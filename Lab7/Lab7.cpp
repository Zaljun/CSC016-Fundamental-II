//ListInt.h
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

//----------------------------------------------------------------------------------------

//ListInt.cpp
#include "ListInt.h"

ListInt::ListInt(int new_capacity) // default and specific constructor
{
    assert(new_capacity >= 0);
    cout << "Default + specific constructor " << endl;
    ptr_list = new int[new_capacity]; // allocate memory on the heap 
                                      // (dynamic memory)
    size = 0;  // empty list
    capacity = new_capacity;                          
}


ListInt::ListInt(const ListInt &other)       // copy constructor
: capacity(other.capacity), size(other.size) //initializer list
{
    cout << "Copy constructor " << endl;
    ptr_list = new int[capacity];
    for (int i = 0; i < size; i++)
        ptr_list[i]  = other.ptr_list[i];
}

ListInt::~ListInt() // destructor-deallocate heap memory for the list items
{
    cout << "Destructor" << endl;
    delete [] ptr_list; // deallocate heap memory pointed by ptr_list
}



bool ListInt::is_empty() const
{
	if(size == 0)
	{
		cout << "List is empty" << endl;
		return true;
	}
	else
	    return false;
}

bool ListInt::is_full() const
{
	if(size == capacity)
	{
		cout << "List is full" << endl;
		return true;
	}
	else
	    return false;
}

int ListInt::get_size() const
{
	return size;
}

int ListInt::get_capacity() const
{
	return capacity;
}

void ListInt::display() const
{
    cout << "size = " << size << endl;
    cout << "capacity = " << capacity << endl;
    for (int i = 0; i < size; i++)
        cout << ptr_list[i] << ' ';
    cout << endl; 
}

int ListInt::insert(int new_item, int pos)
{
    assert (pos >= 0 && pos <= size);
    if(size == capacity)
    {
        cout << "Sorry, list is full" << endl;
        return -1;  // full list, unsuccessful insert
    }
        // 1. move all items from
    for(int i = size-1 ; i >= pos; i--)
        ptr_list[i+1] = ptr_list[i];
        // 2. insert item at pos
    ptr_list[pos] = new_item;
        // 3. increment size
    size++;
    return 0;  // successful insert
}

int ListInt::remove(int pos)
{
	assert(pos >= 0 && pos < size);
	if(size == 0)
	{
		cout << "Sorry, list is empty" << endl;
		return -1;
	}
	for(int i = pos; i < size - 1; i++)
	  ptr_list[i] = ptr_list[i+1];
	size --;
	return 0;
}

void ListInt::sort()
{
	int i, j, temp;
	for(i = 1; i < size; i++)
	{
		j = i; 
		while(ptr_list[j] < ptr_list[j-1] && j > 0)
		{
			temp = ptr_list[j-1];
			ptr_list[j-1] = ptr_list[j];
			ptr_list[j] = temp;
			j--;
		}
	}
}

int ListInt::search(int item)
{
	for(int i = 0; i < size; i++)
	{
		if(ptr_list[i] == item)
		  return i;
	}
	return -1;
}

int ListInt::item_at(int pos)
{
	assert(pos >= 0 && pos < size);
	return ptr_list[pos];
}

//--------------------------------------------------------------------------

//testListInt.cpp
#include "ListInt.h"

int main()
{
    // test constructors
    ListInt l1, l2(10), l3(l2);
    l1.display();
    l2.display();
    l3.display();
    
    l1.insert(20);    
    l1.display();
    l1.insert(30);    
    l1.insert(15, 2); 
    l1.display();
    l1.insert(17,2);
    l1.insert(-2,3);
    l1.display();
    l1.insert(0,1);
    l1.insert(5);
    l1.insert(7,5);
    l1.display();
    
    l1.remove(3);
    l1.display();
    
    l2.is_empty();
    l1.is_full();
    
    cout << "l1: search index of 0: " << l1.search(0) << endl;
    cout << "l1: item of index 1: " << l1.item_at(1) << endl;
    
    l1.sort();
    l1.display();
}

/*
Sample:
Default + specific constructor
Default + specific constructor
Copy constructor
size = 0
capacity = 100

size = 0
capacity = 10

size = 0
capacity = 10

size = 1
capacity = 100
20
size = 3
capacity = 100
30 20 15
size = 5
capacity = 100
30 20 17 -2 15
size = 8
capacity = 100
5 30 0 20 17 7 -2 15
size = 7
capacity = 100
5 30 0 17 7 -2 15
List is empty
l1: search index of 0: 2
l1: item of index 1: 30
size = 7
capacity = 100
-2 0 5 7 15 17 30
Destructor
Destructor
Destructor
*/
