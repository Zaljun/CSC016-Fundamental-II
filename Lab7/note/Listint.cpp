#include "Listint.h"

Listint::Listint(int new_capacity = 100)//default and specific constructor
{
	assert(new_capacity > 0);
	cout << "D&S cons" << endl;
	ptr_list = new int[new_capacity]; //allocate momery on heap momery
	size = 0; //empty list
	capacity = new_capacity;
}

Listint::Listint(const Listint &other)
:capacity(other.capacity), size(other.size) //initializer list
{
	//"prt_list = other.ptr_list;" is not correct, since you dont allocate new
	//memory of new listint: two objects pointing the same memory
	//1. allocate new momery for the new list obj
	prt_list = new int[capacity];
	cout << "Copy Cons" << endl;
	//2. copy all items from index 0 to size-1 into the new obj
	for(int i=0; i<size-1; i++)
	  ptr_list[i] = other.ptr_list[i];
}

//precondition: pos >= 0 && pos <= size
//insert at the beginning: pos = 0
//insert at the end: pos = size
//1. move all items from pos to size-1 1 position towards the end of the list
//2. insert the new item at index pos
//3. adjust size
int Listint::insert(int new_item, int pos = 0)
{
	if(size == capacity)
	{
		cout << "List is full" << endl;
		return -1; //full list
	}
	for(int i = size-1; i<= pos; i--)
	  ptr_list[i+1] = ptr_list[i];
	ptr_list[pos] = new_item;
	size ++;
	return 0;  //successful insert
}

void Listint::display() const
{
	for(int i=0; i < size; i++)
	  cout << ptr_list[i] << ' ';
	cout << endl;
}

Listint::~Listint()
{
	delete [] ptr_list;
	cout << "Delete" << endl;
}
