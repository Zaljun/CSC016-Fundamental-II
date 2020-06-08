// Lab 4 areas.cpp 
// WRITE A COMMENT BRIEFLY DESCRIBING THE PROGRAM. 
// NAME: Zhaojun Jia
// INCLUDE ANY NEEDED FILES HERE.
#include <iostream>
#include <cmath>
using namespace std;

int main()
{  
   // DEFINE THE NAMED CONSTANT PI HERE AND SET ITS VALUE TO 3.14159
   const double PI = 3.14159;
   // DECLARE ALL NEEDED VARIABLES HERE. GIVE EACH ONE A DESCRIPTIVE
   // NAME AND AN APPROPRIATE DATA TYPE. 
   int choice;
   double area, length, wide, radius;
   // WRITE STATEMENTS HERE TO DISPLAY THE 4 MENU CHOICES.
   cout << "Program to calculate aeas of bojects" << endl;
   cout << "      " << "1 -- square" << endl;
   cout << "      " << "2 -- circle" << endl;
   cout << "      " << "3 -- right triangle" << endl;
   cout << "      " << "4 -- quit" << endl;
   // WRITE A STATEMENT HERE TO INPUT THE USER'S MENU CHOICE.
   cin >> choice;
   // USE AN IF/ELSE IF STATEMENT TO OBTAIN ANY NEEDED INPUT INFORMATION 
   // AND COMPUTE AND DISPLAY THE AREA FOR EACH VALID MENU CHOICE.
   // IF AN INVALID MENU CHOICE WAS ENTERED, AN ERROR MESSAGE SHOULD
   // BE DISPLAYED.
   while (choice < 1 || choice > 4)
   {  cout << "Invalid input. Enter an integer between 1 and 4: ";
      cin  >> choice;
   }
   if (choice == 1)
   {
	   cout << "Length of the square: ";
	   cin >> length;
	   cout << "Wide of the square: ";
	   cin >> wide;
	   area = length * wide;
	   cout << "Area = " << area;
   }
   else if(choice == 2)
   {
	   cout << "Radius of the circle: ";
	   cin >> radius;
	   area = PI * radius * radius;
	   cout << "Area = " << area;
   }
   else if (choice == 3)
   {
	   cout << "Length of the right triangle: ";
	   cin >> length;
	   area = 0.5 * (length * 0.865 *length);
	   cout << "Area = " << area;
   }
      
   return 0;
}
