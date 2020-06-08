// example of reading/writing to a file
// read a set of double values from a file called numbers.txt
// compute the average and write the value to an output file called gpa.txt

#include <iostream>
#include <fstream>
//#include <string>  // not needed
//#include <cstdlib> // not needed
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
  
  assert(inFile  != NULL);  // checks that the input file is open
  assert(out_gpa != NULL);  // checks that the output file is open
  
  double value; 
  int count  = 0;
  double sum = 0;
  double min_val =  1e10;
  double max_val = -1e10;
  
  while (inFile >> value)  // read a double value from the file until end of 
                        // the file is reached and the extraction operator >>
                        // returns false
  {
     cout << value << endl;
     // add code to check the min_val against value. update min_val if needed
     // add code to check the max_val against value. update max_val if needed
     
     sum += value;
     count++;
  }
   out_gpa << sum/count << endl;
}
