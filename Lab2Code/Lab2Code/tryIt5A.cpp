// Lab 5 tryIt5A -- Using the increment and decrement operators
// Determine what each output statement will print. Then run the
// program to see if you are correct. If any of your answers are
// wrong, figure out why the program produced the output it did.
#include <iostream>
using namespace std;

int main()
{
   int a = 5, b = 5,
       c = 3, d = 7; 
   
   cout << a-- << ' ';
   cout << a   << ' ';
   cout << a-- << ' ' << a-- << ' ';
   cout << a-- << ' ' << a << endl;
   
   cout << ++b << ' ';
   cout << b   << ' ';
   cout << ++b << ' ' << ++b << ' ';
   cout << ++b << ' ' << b << endl;
   
   a = c++ * d--;
   cout << a << "  " << c << ' ' << d << endl; 
           
   return 0;
}
