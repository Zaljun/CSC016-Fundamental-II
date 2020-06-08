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
