// example of reading/writing to a file
// read a set of double values from a file called numbers.txt
// compute the average and write the value to an output file called gpa.txt

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
  ifstream inFile;
  inFile.open("numbers.txt"); // open a file for reading
                              // inFile - input stream handler (similar to cin)
                              //  reads input from the file into the program
   
  ofstream out_gpa("gpa.txt");  // open a file for writing
                            // out_gpa is an output stream handler (similar to
                            // cout 
                            // sends data from the program to the output file
                      
  double value; 
  int count = 0;
  double sum = 0;
  
  while (inFile >> value)  // read a double value from the file until end of 
                        // the file is reached and the extraction operator >>
                        // returns false
  {
     cout << value << endl;
     sum += value;
     count++;
  }
   
   out_gpa << sum/count << endl;

}

