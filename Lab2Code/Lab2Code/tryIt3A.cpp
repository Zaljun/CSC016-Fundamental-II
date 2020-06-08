// Lab 3 tryIt3A -- Evaluating arithmetic expressions
// Determine what each output statement will print. Then run 
// the program to see if you are correct. If any of your answers 
// are wrong, figure out why the program behaved as it did.
#include <iostream>
#include <cmath>
using namespace std;

int main()
{   int someInt,
		  w = 5, x = 9, y = 2, z = 7;

	 char someChar = 'A';

	 cout << "tryIt3A output \n";

	 z += 3;
	 cout << z << "  " << z % w << endl;

	 z *= w + y;
	 cout << z << endl;

	 z -= 60.1;
	 cout << z << endl;

	 cout << (x-1) / (x-w) * y << endl;

	 cout << (x-1) / ((x-w) * y) << endl;

	 cout << static_cast<double>(x) / y << endl;

	 cout << x / y << endl;

	 cout << (w + x % 7 / y) << endl;

	 cout << (abs(y - w) + sqrt(x)) << endl;

	 someInt = someChar;
	 cout << someChar << "  "
			<< someInt << endl;
         
    return 0;
}
