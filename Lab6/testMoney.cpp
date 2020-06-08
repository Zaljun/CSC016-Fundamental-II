#include "Money.h"

int main()
{
	Money money1;
	Money money2(2,3);
	money1.display();
	money2.display();
	money1.add(9,99);
	money1.display();
	money1.add(money2);
	money1.display();
	money1.sub(0,50);
	money1.display();
	money1.sub(money2);
	money1.display();
	money1.isBigger(money2);
	cout << money1.to_string();
}

/*
Sample
Default constructor
Specific constructor
$0.0
$2.3
$9.99
$12.2
$11.52
$9.49
Yes
$9.49
*/
