#include "Dice.h"

// compile this using:
// g++ -o testDice testDice.cpp Dice.cpp
int sumDice(Dice arrayD[], int size);

int main()
{
 	srand(time(NULL));
 	
 	Dice d1(5);   // calls specific constructor d1.face will be 5
 	Dice d2(d1);  // d2 will be a copy of d1 (same values for each data member)
 		 		  // d2(d1) = calls a copy constructor
 		 		  // Copy constructor = copies the values of each data member
				  // from an existing object into a new object 
	Dice d3;       //
	
	d3 = d2;      // assignment operator = function provided by the compiler
 	   	 		  // that will copy each data member value of the object
  	 		  	 // on the right side (d2) into the corresponding data member of
  	 		  	 // the object on the left side (d3)
				 // assignment operator can be called for any existing objects
				 // copy constructor only is called for a new object

   if (d3.isGreater(d2))    // operator ==  should be a non-member function 
     cout << "Equal " << endl;
					  
	cout << "d1 is ";
	d1.display(); 
	
	cout << "d2 is ";
	d2.display(); 
	
	cout << "d3 is ";
	d3.display();			   
 	
 	/*
 	// declare a new Dice object called d1
 	//  ClassName ObjectName;
 	// Default constructor is called because d1 has
 	// no specific instructions (parameters) on how 
 	// its data members should be initialized
 	Dice d1;
 	
 	// Test specific constructor
 	// declare a new dice object called d2 with a face set 
 	// to 4
	// Specific constructor is called
 	Dice d2(4);
 	
 	// Test setFace();
 	// set the face of d1 object to 5
 	// d1 has to call the function setFace 
 	// d1 = calling object
 	d1.setFace(5);
 	
 	// Test display function
 	cout << "Data of d1 object" << endl;
    d1.display();
 	cout << "Data of d2 object" << endl;
 	d2.display();
 	
 	// Test roll() function
 	// roll each dice
 	d1.roll();
 	d2.roll();
 	
 	// Test getFace() function
 	// display the sum of the two dice objects
 	
 	cout << "Sum of d1 and d2 faces is " << 
	 	 d1.getFace() + d2.getFace() << endl;
	 	 
    // roll both dices 100 times. Count the number of
    // times the sum is equal to 12. 
    int counter = 0;
    for (int i = 0; i < 100; i++)
    {
	 	// roll d1 and roll d2
	 	d1.roll();
	 	d2.roll();
	 	// compute the sum of d1 and d2
	 	int sum = d1.getFace() + d2.getFace();
	 	// To count the doubles use the code below
	    // if (d1.getFace() == d2.getFace())
	 	//     countDoubles++;
	 	// if sum == 12 add it to a counter
	 	if (sum == 12)
	 	   counter++;
	}
    cout << "12 appeared " << counter << " times in 100 rolls" << endl;
    
    cout << "NEW TESTS " << endl;
    // declare a new dice object called myDice. 
	Dice myDice(4);  // the default constructor is called (no input parameters)
	// display the face of myDice
	myDice.display(); 
	// roll myDice
	myDice.roll();
	// display the face of myDice 
    myDice.display();
    
    
    // add code to compute the number of doubles in 
    // a 100 rolls of the two dice objects
    
    //Declare an array of 5 dice objects. 
	// Write a function (sumDice) 
	// that rolls all dice objects 
	// and computes and returns the sum of all 
	// 5 dice objects in the array. 
	// Write a while loop in main that calls 
	// the function sumDice until the number 
	//returned is even and greater than 10. 
	// Print the number.
   
    // Declare an array of 5 dice objects
    // static array 
    Dice array[5]; // the default constructor is called
 	               // 5 times, once for each dice object 
              	  // in the array
    int sumAll = 0;
    int nrTries = 0;
    do
    {
	  	sumAll = sumDice(array, 5);
	  	nrTries++;
	}while(sumAll % 2 == 1 || sumAll <= 10);
    
    cout << "sumAll = " << sumAll << endl;
	cout << "Nr tries = " << nrTries << endl; 
    */
    
 	char c;
 	cin >> c;
} // end of main()

int sumDice(Dice arrayD[], int size)
{
 	int sum = 0;
 	for (int i = 0; i < size; i++)
 	{
 	 	// roll each dice
 	 	arrayD[i].roll();
 	 	// sum their faces
 	 	sum = sum + arrayD[i].getFace();
 		
	}
	// return the sum
    return sum;
}

