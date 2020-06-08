// test the ListInt objects and function members

#include "ListInt_BB.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    // test constructors
    ListInt l1, l2(10), l3(l2);
    l1.display();
    l2.display();
    l3.display();
    
    l1.insert(20);    // insert at 0
    l1.display();
    l1.insert(30);    // insert at 0
    l1.display();
    l1.insert(15, 2); // insert at the end
    l1.display();
    
    // see how the destructor is called. 
    
}
