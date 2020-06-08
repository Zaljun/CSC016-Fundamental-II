#include "Account.h"

int main()
{
	Account acc1;
	Account acc2(12,68);
	acc1.display();
	acc2.display();
	
	acc2.withdraw(1,99);
	acc2.display();
	acc2.deposit(3,14);
	acc2.display();
	
	Money transfer(7,23);
	acc2.is_valid(transfer);
	acc2.transfer_into(acc1,transfer);
	acc1.display();
	acc2.display();
	acc2.is_valid(1,12);
	acc2.transfer_from(acc1,transfer);
	acc1.display();
	acc2.display();
	
}

/*
Sample:
Default constructor
Default constructor
ID: 1740948824
$0.0
ID: 5517115276
$12.68
ID: 5517115276
$10.69
ID: 5517115276
$13.83
Specific constructor
ID: 5517115276
$13.83
Yes
ID: 1740948824
$7.23
ID: 5517115276
$6.60
Yes
ID: 1740948824
$0.0
ID: 5517115276
$13.83
*/
