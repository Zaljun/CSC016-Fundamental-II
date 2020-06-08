// example allocate and use dynamic memory (heap memory)

#include <iostream>
using namespace std;

void display(int *ptr_array, int nr_items);

int main()
{
    int size = 0;
    while (size <= 0)
    {
        cout << "Enter the size of the array you need: " << endl;
        cin >> size;
    }
    
    // static array: int array[10];
    // dynamic array (ptr_int points to a dynamic array)
    int *ptr_int = new int[size];  // allocate memory on the heap for 'size'
                                   // ints, ptr_int stores the memory address of
                                   // the first item 
                                   
    // initialize the new array 
    for (int i = 0; i < size; i++)
        ptr_int[i] = 0;
        
    // pass the array to a display function
    display(ptr_int, size);
    
    // deallocate or free the heap memory for the array 
    delete [] ptr_int;  // [] pointer points to more than one item (array)
}

void display(int *ptr_array, int nr_items)
{
    for (int i = 0; i < nr_items; i++)
        cout << ptr_array[i] << ' ';
    cout << endl;
}



