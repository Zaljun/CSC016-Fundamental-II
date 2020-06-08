#include "Dice.h" 	
	
// compile the Dice.cpp after you add each function
// g++ -c Dice.cpp
	
// default constructor: initializes the face of a new
// Dice object to 1

Dice::Dice()
{
  cout <<  "Default constructor " << endl;
  face = 1;	// not redeclaring the data member face	
}


// specific constructor: initializes the face of a new
// Dice object to newFace 
// Pre-condition: newFace is a valid number
// call setFace function inside Dice(int newFace)
Dice::Dice(int newFace)
{
    cout << "Specific constructor " << endl; 
   	setFace(newFace);    
}

// 10/17/14 Added definition copy constructor
Dice::Dice(const Dice &old)
{
    cout << "Inside copy constructor " << endl;
 	face = old.face;			 
}

Dice & Dice::operator=(const Dice &right)
{
 	 cout << "Inside assignment operator " << endl;
 	 face = right.face;
 	 return *this; // this = pointer to the calling object
}

// Sets face to the value in otherFace
// Pre-condition: otherFace is valid 
void Dice::setFace(int otherFace)
{
 	assert(otherFace >= 1 && otherFace <= 6);
	face = otherFace;  
}


// Changes the value of face to a random value between 1 and 6
void Dice::roll()
{
 	 face = rand()%6 +1; 
}
	
// returns the face value of a Dice object
int Dice::getFace() const
{
 	return face;
}
	
	// displays the face value of a Dice object
void Dice::display() const
{
 	 cout << "This dice has " << face << " on top" << endl; 
 }

bool Dice::isGreater(const Dice &other) const
{
	// access the face of the calling object
	// face
	// access the face of the object other
	// other.face
	// call function display() for the calling object
	// display();

	// call function display() for the object other
	// other.display();
	
	bool result;
	
	if ( face  >  other.face)
	    result = true;
	else
		result = false;
	return result;
	
	
} 
  
  
  
  
  
  
