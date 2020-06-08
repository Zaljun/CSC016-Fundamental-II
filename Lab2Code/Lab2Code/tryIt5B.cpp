// Lab 5 tryIt5B -- Examining looping structures
// Determine what each output statement will print. Then run the
// program to see if you are correct. If any of your answers are
// wrong, figure out why the program produced the output it did.
#include <iostream>
#include <cstring>
#include <cmath>

#include <iomanip>

using namespace std;

int main()
{
   char x = 'a', y = 'a';
   while (x <= 'e')
   {
	 while (y <= 'e')
	 {
		 cout << x << y <<endl;
		 y++;
	 }
	 y = 'a';  
	 x++;
   }
}
