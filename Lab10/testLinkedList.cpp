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
