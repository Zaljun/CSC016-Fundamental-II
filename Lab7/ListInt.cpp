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
