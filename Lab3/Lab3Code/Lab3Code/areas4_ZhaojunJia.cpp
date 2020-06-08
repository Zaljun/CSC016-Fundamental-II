// Lab 4 areas.cpp 
// WRITE A COMMENT BRIEFLY DESCRIBING THE PROGRAM. 
// NAME: Zhaojun Jia

#include <iostream>
#include <cmath>

using namespace std;

void displayMenu();
int getChoice(int min, int max);
double findSquareArea();
double findCircleArea();
double findTriangleArea();

const double PI = 3.14159;

int main()
{  
   int choice;
   char continu;
   do
   {
	   displayMenu();
       choice = getChoice(1,4);
       /*while (choice < 1 || choice > 4)
       {  cout << "Invalid input. Enter an integer between 1 and 4: ";
          cin >> choice;
       }*/
       if (choice == 1)
       {
	      cout << "Area = " << findSquareArea() << endl;
       }
       else if(choice == 2)
       {
	      cout << "Area = " << findCircleArea() << endl;
       }
       else if (choice == 3)
       {
	      cout << "Area = " << findTriangleArea() << endl;
       }
       else
       return 0;
       cout << endl << "Do you want to continue? " << endl << "press Y to continue" << endl;
       cin >> continu;
   }while (continu == 'Y' || continu == 'y');
   return 0;
}

void displayMenu()
{
   cout << "Program to calculate areas of bojects" << endl;
   cout << "      " << "1 -- square" << endl;
   cout << "      " << "2 -- circle" << endl;
   cout << "      " << "3 -- right triangle" << endl;
   cout << "      " << "4 -- quit" << endl;	
}

int getChoice(int min, int max)
{
   int input;
   cin >> input;
   while (input < min || input > max)
   {  cout << "Invalid input. Enter an integer between 1 and 4: ";
      cin  >> input;
   }
   return input;
}

double findSquareArea()
{
	double area, length, wide;
    cout << "Length of the square: ";
    cin >> length;
    cout << "Wide of the square: ";
    cin >> wide;
    area = length * wide;
    return area;
    //cout << "Area = " << area;		
}

double findCircleArea()
{
	double area, radius;
    cout << "Radius of the circle: ";
    cin >> radius;
    area = PI * radius * radius;
    //cout << "Area = " << area;
    return area;
}

double findTriangleArea()
{
	double length, area;
    cout << "Length of the right triangle: ";
    cin >> length;
    area = 0.5 * (length * 0.865 *length);
    //cout << "Area = " << area;
    return area;
}

/*
sample: 
Program to calculate areas of objects
      1 -- square
      2 -- circle
      3 -- right triangle
      4 -- quit
0
Invalid inout. Enter an integer between 1 and 4: 5
Invalid inout. Enter an integer between 1 and 4: 1
Length of the square: 1.5
Wide of the square: 1
Area = 1.5

Do you want to continue?
press Y to continue
y
Program to calculate areas of objects
      1 -- square
      2 -- circle
      3 -- right triangle
      4 -- quit
2
Radius of the circle: 3
Area = 28.2743

Do you want to continue?
press Y to continue
y
Program to calculate areas of objects
      1 -- square
      2 -- circle
      3 -- right triangle
      4 -- quit
3
Length of the right triangle: 2
Area = 1.73

Do you want to continue?
press Y to continue
y
Program to calculate areas of objects
      1 -- square
      2 -- circle
      3 -- right triangle
      4 -- quit
4
*/
