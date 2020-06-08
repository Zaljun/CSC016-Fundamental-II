// HEADER FILE ListInt class declaration 

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
           
            int insert(int new_item, int pos = 0);
            void display() const; // accessor function 
            
            bool is_empty() const; 
                                // returns true if the list has no items stored
                                //(size == 0)
            bool is_full() const;  //returns true if the list is full (size == capacity)
            int  get_size() const;   // returns the size of the list
            int  get_capacity() const; // returns the capacity of the list
            
            int remove(int pos); 
            // deletes an item from the list at index pos
            // returns -1 if the list is empty and it cannot delete anything
            // moves all items from pos+1 to size-1 one position towards the
            // beginning of the list, adjusts size and returns 1 
    
    
            void display();  // displays the content of the lisst
    
            void sort();   // sorts the items in the list (any sorting algorithm)
    
            int search(int item); // search for an item in the list (linear search) returns the index of the location if found, or -1 if not found. 
    
            int item_at(int pos);  
             // returns the value stored in the list at index pos.
             // assert pos < size && pos >= 0
    
};
#endif 
