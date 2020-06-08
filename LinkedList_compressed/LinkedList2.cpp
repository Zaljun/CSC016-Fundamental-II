//LinkedList implementation file
#include "LinkedList.h"
#include <iostream>
#include <cassert>
using namespace std;

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
    my_size = 0; 
}

/***** Class destructor *****/
 /*----------------------------------------------------------------------
     Deallocates the memory of a LinkedList object.
     Nodes are stored in dynamic memory
 ------------------------------------------------------------------*/
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
    my_size = 0;
}



 /***** Copy constructor *****/
 // called LinkedList new_list(old_list); // new_list copy of the old_list
 // deep copy and shallow copy
 // shallow copy:  copy value of the data members from old_list to new_list
//                 first   = old_list.first
//                 my_size = old_list.my_size
//          new_list points to the old_list nodes !!!!
//          no new nodes in the new_list
// deep copy:   
//   for each node in the old_list 
//          allocate memory for a new node object
//          copy the data from the old_list node to the new_list node
//          insert new node object in the new_list
//
/*----------------------------------------------------------------------
     Construct a copy of a LinkedList object..
-----------------------------------------------------------------------*/
LinkedList::LinkedList(const LinkedList & origList)
{
        first = 0;
        my_size = 0; 
        // ptrOrig a pointer to a node in origList
        Node *ptr_orig = origList.first;
        // ptr  = a pointer to a node in the new list
        Node *ptr;
        // first node is special -> sets the value of first in the new node
        
        // while ptrOrig is not null
        while (ptr_orig != 0)
        {
        //     allocate new memory for a new Node
               Node *ptr_new   = new Node();
        //     copy the data from the origList node (ptrOrig) to the new Node
               ptr_new->data  = ptr_orig->data;
        //     link the node at the end of the new list
               if (first == 0) // add the first node
                 first     =  ptr_new;
               else  //ptr points to the last node, ptr_new points to the new node
                    ptr->next  = ptr_new; 
               
        //      advance to the next node in origList
               ptr_orig  =  ptr_orig->next;
        //     make ptr point to the last node in the new list (ptr_new)
               ptr  = ptr_new;

        }
        my_size = origList.my_size;
}

/***** Assignment operator *****/
/*----------------------------------------------------------------------
     Assign a copy of a List object to the current object.

     Precondition: none 
     Postcondition: A copy of origList has been assigned to this
          object.  A reference to this list is returned.
-----------------------------------------------------------------------*/
LinkedList& LinkedList::operator=(const LinkedList & origList)
{
    // if self assignment do nothing (l = l)
    // this - pointer to the calling object (pointer to the old list)
    if (this == &origList)
        return *this;
    else
    {
    //  deallocate memory for the old list object - node by node
    //  this is the code we did in the destructor
        // deallocate memory for each node object in the list
        Node *ptr = first;
    
        while (first != 0)  // traverse the list and deallocate memory for first
                        // node until the list is empty
        {
            ptr = first;
            first = first->next;
            delete ptr;
        }
        my_size = 0;
    //  allocate memory for new nodes and copy data from origList nodes to them 
    //  this is similar to the copy constructor code
    
        Node *ptr_orig = origList.first;
        // ptr  = a pointer to a node in the new list
        // first node is special -> sets the value of first in the new node
        
        // while ptrOrig is not null
        while (ptr_orig != 0)
        {
        //     allocate new memory for a new Node
               Node *ptr_new   = new Node();
        //     copy the data from the origList node (ptrOrig) to the new Node
               ptr_new->data  = ptr_orig->data;
        //     link the node at the end of the new list
               if (first == 0) // add the first node
                 first     =  ptr_new;
               else  //ptr points to the last node, ptr_new points to the new node
                    ptr->next  = ptr_new;  
        //     advance to the next node in origList
               ptr_orig  =  ptr_orig->next;
        //     make ptr point to the last node in the new list (ptr_new)
               ptr  = ptr_new;

        }
        my_size = origList.my_size;
        return *this;
    }
}


 /***** empty operation *****/
/*----------------------------------------------------------------------
     Check if a list is empty.
 -----------------------------------------------------------------------*/
bool LinkedList::empty() const
{
    return (my_size == 0);
}

/***** insert and erase *****/
/*----------------------------------------------------------------------
     Insert a value into the list at a given position.
-----------------------------------------------------------------------*/
void LinkedList::insert(ElementType item, int pos)
{
    assert(pos >= 0 && pos <= my_size);
    // if pos == 0 insert at the beginning - change the value of first
    // or insert in an empty list
    if (pos == 0)
    {
        Node *ptr_new = new Node();
        ptr_new->data = item;
        
        ptr_new->next = first;  // new Node points to the first node in the list
        first         = ptr_new; // first points to new Node
    }
    else // insert in the middle
    {
        Node *ptr_new = new Node();
        ptr_new->data = item;
        
        // traverse the list until ptr points to the node at pos and ptr_pred
        // points to the node before it 
        Node *ptr = first, *ptr_pred = first;
        for (int i = 0; i < pos; i++)
        {
            ptr_pred = ptr;
            ptr      = ptr->next;
        }
        
        // link new node (ptr_new) to the list from node pointed by ptr
        ptr_new->next  = ptr;
        ptr_pred->next = ptr_new;
    }
    my_size++;
}

 /*----------------------------------------------------------------------
     Remove a value from the list at a given position.
     pos >= 0 and pos < mySize
     
     don't erase from an empty list
     erase the first node
     erase in the middle
   ----------------------------------------------------------------------*/
 void LinkedList::erase(int pos)
 {
    assert(pos >=0 && pos < my_size);
    if (empty())
    {
        cout << "Cannot erase in an empty list " << endl;
        return;
    }
    // erase at the beginning
    if (pos == 0)
    {
        Node *ptr_delete = first;
        first = first->next;
        delete ptr_delete;
    }
    else// erase in the middle
    {
        Node *ptr_delete = first, *ptr_pred = first;
        for (int i = 0; i < pos; i++)
        {
            ptr_pred = ptr_delete;
            ptr_delete = ptr_delete->next;
        }
        ptr_pred->next = ptr_delete->next;
        delete ptr_delete;
    }
    my_size--;
 }
 
 
/***** output *****/
 void LinkedList::display() const
 {
    Node *ptr = first;
    while (ptr != 0)
    {
        cout << ptr->data << ' ';
        ptr = ptr->next;
    }
    cout << endl;
 }
 
 
 //search items with particular values in the list
int LinkedList::search(ElementType val) const
{}

   //reverse the order of the nodes in a list
void LinkedList::reverse()
{}
   
   //merge two sorted LinkedList objects in order
void LinkedList::merge(const LinkedList &other)
{}
 
 
 
 
 
 



