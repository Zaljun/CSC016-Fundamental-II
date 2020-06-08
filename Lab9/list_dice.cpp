#include "Dice.h"
#include <list>
#include <iostream>

using namespace std;
int main()
{
    list <Dice> my_dice;
    // add 10 dice objects in a loop
    Dice d;
    for (int i = 0; i < 10; i++)
    {
        d.roll();
        my_dice.push_front(d);  // a copy of d is inserted in the list 
                                // in the front (push_front()
    }
    
    // display all 10 Dice objects
    // iterate through the list
    // it = iterator = pointer to an item in the list
    // begin() - sets the iterator on the first item in the list
    // end()   - checks if the iterator is pass last item in the list
    
    for (list<Dice>::iterator it=my_dice.begin(); it !=my_dice.end(); ++it)
            cout<< it->getFace() << ' ';
    cout << endl;

    // sort the list
    my_dice.sort();

    cout << "Sorted dice list " << endl;
        for (list<Dice>::iterator it=my_dice.begin(); it !=my_dice.end(); ++it)
            cout<< it->getFace() << ' ';
    cout << endl;

}
