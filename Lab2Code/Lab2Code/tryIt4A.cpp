// Lab 4 tryIt4A -- Using relational and logical operators
// Determine what each output statement will print. Then run the
// program to see if you are correct. If any of your answers are
// wrong, figure out why the program produced the output it did.
#include <iostream>
using namespace std;

int main()
{
   cout << ( 3 == 4) << endl;
   cout << ( 3 == 3) << endl;
   cout << ( 5 == 3 + 2) << endl << endl;
   
   cout << (7 > 5) << endl;
   cout << (7 > 5 + 2) << endl;
   cout << (2 >= 8 % 3) << endl << endl;
   
   cout << (8 < 6) << endl;
   cout << (3 * 5 < 2 * 9 - 1) << endl;
   cout << (5 * 4 <= 40 / 2) << endl << endl;
   
   cout << (3 != 5) << endl;
   cout << (3 != 9 - 2 * 3) << endl;
   cout << (10 != (4 * 5) / 2) << endl << endl;
   
   cout << (5 > 6 && 3 < 4) << endl;
   cout << (5 > 6 || 3 < 4) << endl; 
   cout << (!(7 > 6)) << endl << endl;
   
   cout << ( 2 * 3 == 6 && !(1 > 2) ) << endl;
   cout << ( !(2 * 3 == 6 && 1 > 2) ) << endl;
   cout << ( !(2 * 3 == 6 && 1 != 2) ) << endl;
   
   return 0;
}
