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
     and other search/access and traverse functions
-------------------------------------------------------------------------*/

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
    /*----------------------------------------------------------------------
     Construct a (deep) copy of a LinkedList object..
    -----------------------------------------------------------------------*/
 LinkedList(const LinkedList & origList);


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
   ----------------------------------------------------------------------*/

   /***** output *****/
   void display() const;
   
   //search items with particular values in the list
   int search(ElementType val) const;
   
   //reverse the order of the nodes in a list
   void reverse();
   
   //merge two sorted LinkedList objects in order
   void merge(const LinkedList &other);


 private: // data members
         
    class Node{
          // data members of a Node object:
          public: ElementType data;
                  Node *next;
                  Node();
    };
    
   /******** Data Members of a Linked List object********/
   int my_size;   // current size of list stored in array
   Node *first;  // pointer to dynamically-allocated array

}; //--- end of List class


#endif 
