// Lab 4 testNum.cpp
// This program checks to see if a test score is equal to 100. 
// It currently contains a logic error. 
// PUT YOUR NAME HERE.
#include <iostream>
using namespace std;

int main()
{
   int score = 65;          // Initialize student's test score
   
   if (score = 100)
      cout << "You made a perfect score.\n";
   
   if (score != 100)
      cout << "You needed " << 100 - score 
           << " more points for a perfect score.\n";
    
   return 0;
}
