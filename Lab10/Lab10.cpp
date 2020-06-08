/*-- LinkedList.h ---------------------------------------------------------------
  This header file defines the data type List for processing lists.
  Basic operations are:
     Constructor
     Destructor
     Copy constructor
     Assignment operator
     empty:    Check if list is empty
     insert:   Insert an item
     erase:    Remove an item
     display:  Output the list
-------------------------------------------------------------------------*/
#include <iostream>
#include <cassert>

using namespace std;

#ifndef LINKEDLIST
#define LINKEDLIST

typedef int ElementType; // define the type of data in the Linked List
class LinkedList
{
 public:
 /******** Function Members ********/
   /***** Class constructor *****/
   LinkedList();
   /*----------------------------------------------------------------------
     Construct an empty LinkedList object.
   -----------------------------------------------------------------------*/

   /***** Class destructor *****/
   ~LinkedList();
   /*----------------------------------------------------------------------
     Deallocates the memory of a LinkedList object.
     ------------------------------------------------------------------*/

   /***** Copy constructor *****/
   LinkedList(const LinkedList & origList);
   /*----------------------------------------------------------------------
     Construct a copy of a LinkedList object..
   -----------------------------------------------------------------------*/

   /***** Assignment operator *****/
   LinkedList& operator=(const LinkedList & origList);
   /*----------------------------------------------------------------------
     Assign a copy of a List object to the current object.

     Precondition: none 
     Postcondition: A copy of origList has been assigned to this
          object.  A reference to this list is returned.
   -----------------------------------------------------------------------*/

   /***** empty operation *****/
   bool empty() const;
   /*----------------------------------------------------------------------
     Check if a list is empty.
   -----------------------------------------------------------------------*/

   /***** insert and erase *****/
   void insert(ElementType item, int pos);
   /*----------------------------------------------------------------------
     Insert a value into the list at a given position.
   -----------------------------------------------------------------------*/

   void erase(int pos);
   /*----------------------------------------------------------------------
     Remove a value from the list at a given position.
     pos >= 0 and pos < mySize
     
     don't erase from an empty list
     erase the first node
     erase in the middle
     erase the last node
   ----------------------------------------------------------------------*/

   /***** output *****/
   void display() const;
   
   int search(ElementType val) const;
   //search for an item with a particular value in the list
   void reverse();
   //reverse the order of the nodes in a list object
   void merge_inserting(const LinkedList &other);
   //merge two sired LinkedList objects in order by inserting the short one to the large one
   void merge(const LinkedList &other);
   //merge two sired LinkedList objects in order

 private: // data members
         
    class Node{
          // data members of a Node object:
          public: ElementType data;
                  Node *next;
                  Node();
    };
   /******** Data Members of a Linked List object********/
   int mySize;                // current size of list stored in array
   Node *first;  // pointer to dynamically-allocated array

}; //--- end of List class


#endif 


//LinkedList implementation file
#include "LinkedList.h"


/* Constructor for the Node class */
LinkedList::Node::Node()
{
    data = 0;
    next = 0;
}

   /*----------------------------------------------------------------------
     Construct an empty LinkedList object.
   -----------------------------------------------------------------------*/   
LinkedList::LinkedList()
{
    // first, mySize
    first  = 0;  // pointer to nothing  
    mySize = 0; 
}

LinkedList::~LinkedList()
{
    // deallocate memory for each node object in the list
    Node *ptr = first;
    
    while (first != 0)  // traverse the list and deallocate memory for first
                        // node until the list is empty
    {
        ptr = first;
        first = first->next;
        delete ptr;
    }
    mySize = 0;
}

 /***** Copy constructor *****/
/*----------------------------------------------------------------------
     Construct a copy of a LinkedList object..
-----------------------------------------------------------------------*/
LinkedList::LinkedList(const LinkedList & origList)
//LinkedList(const LinkedList & origList);
{
	//check if it's an empty list
	if(origList.empty())
	{
		first  = 0;
		mySize = 0;
	}
	else
	{
		mySize = origList.mySize;
		//build first node
		Node *ptr_orig = origList.first;
		Node *ptr_new = new Node();
		first = ptr_new;
		first->data = origList.first->data;
		//if the original list has more than one node
		//build the other nodes
		if(origList.mySize != 1)
		{
			ptr_orig = ptr_orig->next;
		    Node *ptr = first;
			while(ptr_orig != 0)
			{
				Node *ptr_new = new Node();
				ptr_new->data = ptr_orig->data;
				ptr->next = ptr_new;
				ptr = ptr_new;
				ptr_orig = ptr_orig->next;
			}
		}
	}
}

/***** Assignment operator *****/
LinkedList& LinkedList::operator=(const LinkedList & origList)
{
	//self assignment
	if(this == &origList)
	  return *this;
	//erase the old list
	else
	{
		Node *ptr = first;
		while(ptr != 0)
		{
			first = ptr->next;
			delete ptr;
			ptr = first;
		}
		//deep copy of the original list
	    if(origList.empty())
	    {
	    	first  = 0;
	    	mySize = 0;
	    }
	    else
	    {
		    mySize = origList.mySize;
		    //build first node
		    Node *ptr_orig = origList.first;
		    Node *ptr_new = new Node();
		    first = ptr_new;
		    first->data = origList.first->data;
		    //if the original list has more than one node
		    //build the other nodes
		    if(origList.mySize != 1)
		    {
			    ptr_orig = ptr_orig->next;
		        Node *ptr = first;
			    while(ptr_orig != 0)
			    {
				    Node *ptr_new = new Node();
				    ptr_new->data = ptr_orig->data;
				    ptr->next = ptr_new;
				    ptr = ptr_new;
				    ptr_orig = ptr_orig->next;
			    }
		    }
	    }
	}
	
}
   /*----------------------------------------------------------------------
     Assign a copy of a List object to the current object.

     Precondition: none 
     Postcondition: A copy of origList has been assigned to this
          object.  A reference to this list is returned.
   -----------------------------------------------------------------------*/


 /***** empty operation *****/
/*----------------------------------------------------------------------
     Check if a list is empty.
 -----------------------------------------------------------------------*/
bool LinkedList::empty() const  //return true if empty
{
    return (mySize == 0);
}

/***** insert and erase *****/
/*----------------------------------------------------------------------
     Insert a value into the list at a given position.
-----------------------------------------------------------------------*/
void LinkedList::insert(ElementType item, int pos)
{
    assert(pos >= 0 && pos <= mySize);
    Node *insert = new Node();
    insert->data = item;
    // if pos == 0 insert at the beginning - change the value of first
    if (pos == 0)
    {
        insert->next = first;
        first = insert;
    }
    else // insert in the middle
    {
		Node *ptr = first, *pred = first;
		for(int i = 0 ; i < pos; i++)
		{
			pred = ptr;
			ptr = pred->next;
		}
		insert->next = ptr;
		pred->next = insert;
    }
    mySize++;
}

void LinkedList::erase(int pos)
{
	assert(pos >= 0 && pos < mySize);
	if(empty())
	{
		cout << "This LinkedList is empty." << endl;
		return;
	}
	if(pos == 0)
	{
		Node *ptr = first;
		first = ptr->next;
		delete ptr;
	}
	else
	{
		Node *ptr = first, *pred = first;
		for(int i = 0 ; i < pos; i++)
		{
			pred = ptr;
			ptr = pred->next;
		}
		pred->next = ptr->next;
		delete ptr;
	}
	mySize--;
}
   /*----------------------------------------------------------------------
     Remove a value from the list at a given position.
     pos >= 0 and pos < mySize
     
     don't erase from an empty list
     erase the first node
     erase in the middle
     erase the last node
   ----------------------------------------------------------------------*/

   /***** output *****/
void LinkedList::display() const
{
	if(empty())
	  cout << "The LinkedList is empty" << endl;
	else
	{
		Node *ptr = first;
		while(ptr != 0)
		{
			cout << ptr->data << ' ';
			ptr = ptr->next;
		}
		cout << endl;
	}
}

//search items with particular values in the list
int LinkedList::search(ElementType val) const
{
	Node *ptr = first;
	int pos;
	for(pos = 0; pos < mySize ; pos++)
	{
		if(ptr->data == val)
		  return pos;
		else
		  ptr = ptr->next;
	}
}

   //reverse the order of the nodes in a list
void LinkedList::reverse()
{
	Node *pred = first;
	Node *ptr  = first;
	Node *next = first;
	if(mySize <= 1)
	{
		return;
	}
	else if(mySize == 2)
	{
		first = first->next;
		first->next = 0;
	}
	else
	{
		ptr = pred->next;
		next = ptr->next;
		while(next != 0 )
		{
			ptr->next = pred;
			pred = ptr;
			ptr  = next;
			next = next->next;
		}
		ptr->next = pred;
		first->next = 0;
		first = ptr;
	}
}
   
   //merge two sorted LinkedList objects in order
   //make a deep copy of "other"
   //choose the short one and cut its first node to insert 
   //ptr = first            *ptr contains the first val
   //first = first->next    move first to the next node
   //traverse the large list and compare values with cut node val "ptr->data"
   //insert cut node
   //lg_bfr(large_before)->data <= ptr->data && ptr->data <= lg_aft(large_after)->data 
/*void LinkedList::merge_inserting(const LinkedList &other)
{
	if(mySize >= other.mySize)
	{
		Node *short_first = other.first;
		Node *short_ptr = 0;
		while(short_first != 0)
		{
			short_ptr = short_first;
			short_first = short_first->next; //cut the first node
			
		}
	}
}
*/

  //make a deep copy of other
  //cut the first nodes of the two lists
  //compare each other and choose the smaller one to fit the new list
  //update the two lists, move head to next node
void LinkedList::merge(const LinkedList &other)
{
	Node *other_head = 0;      // make a deep copy of other list
	Node *other_orig = other.first;        
    Node *ptr;       
    while (other_orig != 0)
    {
         Node *ptr_new  = new Node();
         ptr_new->data  = other_orig->data;
         if(other_head == 0) 
             other_head = ptr_new;
         else  
             ptr->next = ptr_new; 
         other_orig  =  other_orig->next;
         ptr  = ptr_new;
    }
    // begin to merge
	Node *merge = 0;
	Node *merge_head = 0;
	Node *ptr_head = first;
	while(ptr_head != 0 && other_head != 0)
	{
		if(ptr_head->data <= other_head->data)
		{
			if(merge_head == 0)
			{
				merge_head = ptr_head;   //if merge node is empty, find its head
				merge = merge_head;
			}
		    else
		    {
				merge->next = ptr_head;  //make the cutted node the new node of merge list
				merge = merge->next;
			}
			ptr_head = ptr_head->next;   //move pointer of cutted list to next node
		}
		else
		{
			if(merge_head == 0)
			{
				merge_head = other_head;
				merge = merge_head;
			}
			else
			{
				merge->next = other_head;
				merge = merge->next;
			}
			other_head = other_head->next;
		}
	}
	if(ptr_head == 0) // if other list has nodes left
		merge->next = other_head;
	if(other_head == 0) // if old list has nodes left
	    merge->next = ptr_head;
	first = merge_head;
	mySize += other.mySize;
}
 
// testLinkedList.cpp
#include "LinkedList.h"
#include <iostream>
using namespace std;

int main()
{
	LinkedList l;
    l.insert(1,0);
    l.insert(2,0);
    l.insert(3,1);
    l.display();
    
        
    // test copy constructor
    cout << "Result of copy constructor: l1(l) " << endl;
    LinkedList l1(l);
    l1.display();
    
    //teat search function
    cout << "Result of searching 1 in l1: " << l1.search(1) << endl;
    cout << "Result of searching 2 in l1: " << l1.search(2) << endl;
    //teat erase
    l.erase(0);
    l.display();
    
        
    // test assignment operator
    cout << "Result of assignment operator l1 = l " << endl;
    l1 = l;
    l1.display();
    
    l.erase(1);
    l.display();
    
    l.erase(0);
    l.display();
    
    //test merge function
    LinkedList l2;
    LinkedList l3;
    l2.insert(6,0);
    l2.insert(5,0);
    l2.insert(1,0);
    l3.insert(8,0);
    l3.insert(7,0);
    l3.insert(5,0);
    l3.insert(2,0);
    l3.insert(1,0);
    l2.display();
    l3.display();
    l2.merge(l3);
    l2.display();
    //test reverse
    l2.reverse();
    l2.display();

}

/*
Sample:
2 3 1
Result of copy constructor: l1(1)
2 3 1
Result of searching 1 in l1: 2
Result of searching 2 in l1: 0
3 1
Result of assignment operator l1 = 1
3 1
3
The LinkedList is empty
1 5 6
1 2 5 7 8
1 1 2 5 5 6 7 8
8 7 6 5 5 2 1 1
*/
