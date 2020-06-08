#include <iostream>

using namespace std;

int main()
{
	int v_int = 4;
	short v_short = 17;
	cout << "The address of v_int is: " << &v_int << endl;
	cout << "The size of v_int int bytes is: " << sizeof(v_int) << endl;
	cout << "The address of v_short is: " << &v_short << endl;
	cout << "The size of v_short in bytes is: " << sizeof(v_short) << endl;
	cout << "-----------------------------------------" <<endl;
	char v_char = 'C';
	cout << "The address of v_char is: " << (void *)(&v_char) << endl;
	cout << "The size of v_char is: " << sizeof(v_char) << endl;
	cout << "-----------------------------------------" <<endl;
	short *ptr_short = 0;
	ptr_short = &v_short;
	char *ptr_char = 0;
	ptr_char = &v_char;
	cout << "The value of ptr_short is: " << ptr_short << endl;
	cout << "The memory address of ptr_short is: " << &ptr_short << endl;
	cout << "The pointed value of ptr_short is: " << *ptr_short << endl;
	cout << "The size of ptr_short is: " << sizeof(ptr_short) << endl;
	cout << "The value of ptr_char is: " << (void *)(ptr_char) << endl;
	cout << "The memory address of ptr_char is: " << &ptr_char << endl;
	cout << "The pointed value of ptr_char is: " << *ptr_char << endl;
	cout << "The size of ptr_char is: " << sizeof(ptr_char) << endl;
	cout << "-----------------------------------------" <<endl;
	int *ptr_int = 0;
	ptr_int = new int;
	*ptr_int = -5;
	cout << "The value of ptr_int is: " << ptr_int << endl;
	cout << "The memory address of ptr_int is: " << &ptr_int << endl;
	cout << "The pointed value of ptr_int is: " << *ptr_int << endl;
	*ptr_int = -10;
	cout << "New value pointed by ptr_int is: " << *ptr_int << endl;
	ptr_int = (int *)ptr_short;
	cout << "New value of ptr_int is: " << ptr_int << endl;
	cout << "New value pointed by ptr_int is: " << *ptr_int <<endl;
}

/*
Q&A
1. 
a) What is the address assigned to v_int? To v_short? 
What is the difference (in Bytes) between them? 
Read the hexadecimal.txt file to learn how to interpret hexadecimal symbols.
A: The address of v_int is: 0x22fe3c
The address of v_short is: 0x22fe3a
The size of addresses is the same, while &v_int uses 4 Bytes and 
&v_short uses 2 Bytes to store values.
&v_int - &v_short = 2

2.
a) What is the address of v_char? What is the difference
(in Bytes) between the address of v_char and the addresses
of v_int and that of v_short? 
A: The address of v_char is: 0x22fe39
&v_int - &v_char = 3(which is 2+1)
&v_short - &v_char = 1

3.
(d) Outputs the size of ptr_short and the size of ptr_char
using the sizeof() operator. Compare them with the size of 
values they point to. Explain the differences.
A:Outputs are in Sample
The sizes of ptr are the same.
Ptr stores address, thus the size of ptr depends on machine system(which is 8 in my laptop).

(e) Draw the memory locations of ptr_short, ptr_char, v_char, 
v_int and v_short and their memory addresses. Explain the relations between them.
A:   Memory Address         | Content
   ptr_int   = &v_int       | v_int  
   0x22fe3c                 |   4
   ptr_short = &v_short     | v_short 
   0x22fe3a                 |   17
   ptr_char  = &v_char      | v_char  
   0x22fe39                 |   C
   &ptr_short               | ptr_short
   0x22fe30                 |   0x22fe3a
   &ptr_char                | ptr_char
   0x22fe28                 |   0x22fe39
   
4.
(f) What happened to -10. Can you still find the memory 
location where -10 is stored? If not, explain why? 
A: -10 is still there, occupying its heap memory while the pointer that points to it has gone.
Thus you can't access -10 through its pointer. However, you can access -10 if you have recorded 
the address of it or read it through a copy of original "gone" pointer.

(g) Draw the memory locations of all variables in your program (from problems 1 to 4) 
and their memory locations. Show the dynamic memory pointed by ptr_int.
A:   Memory Address         | Content
   ptr_int   = &v_int       | v_int  
   0x22fe3c                 |   4
   ptr_short = &v_short     | v_short 
   0x22fe3a                 |   17
   ptr_char  = &v_char      | v_char  
   0x22fe39                 |   C
   &ptr_short               | ptr_short
   0x22fe30                 |   0x22fe3a
   &ptr_char                | ptr_char
   0x22fe28                 |   0x22fe39
   &ptr_int                 | ptr_int
   0x22fe20                 |   0x6c67f0 (point to the heap)
   
                Stack
   - - - - - - - - - - - - - - - - - - - - 
                Heap
   &(new int) = ptr_int     | (new int)
   0x6c67f0                 |   -5
 */
   

/*
Sample:
The address of v_int is: 0x22fe3c
The size of v_int int bytes is: 4
The address of v_short is: 0x22fe3a
The size of v_short bytes is: 2
-----------------------------------------
The address of v_char is: 0x22fe39
The size of v_char bytes is: 1
-----------------------------------------
The value of ptr_short is: 0x22fe3a
The memory address of ptr_short is: 0x22fe30
The pointed value of ptr_short is: 17
The size of ptr_short is: 8
The value of ptr_char is: 0x22fe39
The memory address of ptr_char is: 0x22fe28
The pointed value of ptr_char is: C
The size of ptr_char is: 8
-----------------------------------------
The value of ptr_int is: 0x6c67f0
The memory address of ptr_int is: 0x22fe20
The pointed value of ptr_int is: -5
New value pointed by ptr_int is: -10
New value of ptr_int is: 0x22fe3a
New value pointed by ptr_int is: 262161
*/


