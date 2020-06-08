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

    
    
}
