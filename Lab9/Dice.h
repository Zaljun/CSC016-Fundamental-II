#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
using namespace std;

// to avoid inclusion of multiple definitions of the 
// DICE class use the compiler commands below
#ifndef DICE
#define DICE

// declaration of class Dice
class Dice
{
  private: 
	
	int face; // can only take values between 1 and 6
	// static int countDice = 0; // keep track of how many Dice objects were created
  public: 
	
	// default constructor: initializes the face of a new
	// Dice object to 1
	Dice(); 
	
    // specific constructor: initializes the face of a new
	// Dice object to newFace 
	// Pre-condition: newFace is a valid number
	// call setFace function inside Dice(int newFace)
    Dice(int newFace); 
    
    // 10/17/14: Added copy constructor = copies the data of an existing object into a new object
	Dice(const Dice &old); 
	
	// 10/20/14 added assignment operator
	Dice & operator=(const Dice &right); // returns a reference to a dice object

	
	// Sets face to the value in otherFace
	// Pre-condition: otherFace is valid 
	void setFace(int otherFace); 
	
	// Changes the value of face to a random value between 1 and 6
	void roll(); 
	
	// returns the face value of a Dice object
	int getFace() const;
	
	// displays the face value of a Dice object
	void display() const;
	
	bool operator <(const Dice &other) const;
	// compares the face value of the calling object with the face value 
	// of other object
	// Dice d1, d2;
	//  d1.display();
	//  d1.isGreater(d2); // call isGreater: d1 = calling object d2 = passed object
	
	// bool isGreater(Dice other) // pass a Dice object)
	// other is passed by value 
	
	// change this to pass other by reference (passing the memory address where
	// other is stored
	// bool isGreater(Dice &other) // other is passed by reference
	// &  = reference operator
	
	// change it such that the object other cannot be changed inside the 
	// function isGreater
	
	// bool isGreater(const Dice &other); // other is passed as a reference to a constant object --> other cannot be changed inside isGreater
	
	// isGreater should not change the data of the calling object (d1)
	
	 bool isGreater(const Dice &other) const;
	
};

#endif
