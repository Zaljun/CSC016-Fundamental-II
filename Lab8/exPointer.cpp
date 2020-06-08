#include <iostream>
using namespace std;

int main()
{
 	int i =10, j = 20;
 	cout << "i = "    << i << " The address of i is " << &i << endl;
 	cout << "The size of i in bytes is " << sizeof(i) << endl;
 	cout << "The size of address of i in bytes is " << sizeof(&i) << endl;
 	
    cout << "j = "    << j << " The address of j is " << &j << endl;
 	cout << "The size of j in bytes is " << sizeof(j) << endl;
 	
 	cout << "2. -----------------------------------------------" << endl;
 	
 	int *ptrInt1 = 0; // declare a pointer to an int
                      // initialize ptrInt1 to point to i
 	ptrInt1 = &i;
 	
 	cout << "The value of the pointer is " << ptrInt1 << endl; // expect a memory address
  	cout << "The value pointed by the pointer is " << *ptrInt1 << endl; // expect an integer value
 	cout << "The memory address of the pointer is " << &ptrInt1 << endl; // expect a memory address
 	cout << "The size of the pointer in memory (bytes) is " << sizeof(ptrInt1) << endl;
 	
 	cout << "3. -----------------------------------------------" << endl;
 	
 	int *ptrInt2 = 0; // storage for ptrInt2 is allocated on the stack 
    ptrInt2  = new int; // 4B for the int value are allocated in dynamic memory
    *ptrInt2 = 30;      // initialize the dynamic memory location to 30
    
    cout << "The value of the pointer is " << ptrInt2 << endl; // expect a memory address different than the ones before
 	   	 		 	   	  	  		  	   	  		  	 	   // because it is a memory address in dynamic memory not on the stack
  	cout << "The value pointed by the pointer is " << *ptrInt2 << endl; // expect an integer value
 	cout << "The memory address of the pointer is " << &ptrInt2 << endl; // expect a memory address
 	cout << "The size of the pointer in memory (bytes) is " << sizeof(ptrInt2) << endl;

/*
    
     int size = 0;
     cout << "\n\nDynamic array example" << endl;
     cout << "Enter a size for the array " << endl;
     cin  >> size;
     
     int *ptrArray = new int[size]; // allocate in dynamic memory an array of integers of length size
     
     // ptrArray is a pointer to an array of size integers
     
     // initialize all array elements to 1
     for (int i= 0; i < size; i++)
     {
 	   ptrArray[i] = 1;
 	   cout << ptrArray[i] << ' ';
     }
     cout << endl;
     
     */
    
}


