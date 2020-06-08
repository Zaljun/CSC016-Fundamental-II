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
   
  ofstream out_result("result.txt");  // open a file for writing
                            // out_gpa is an output stream handler (similar to
                            // cout 
                            // sends data from the program to the output file
                      
  double value, max = -999, min = 999; 
  int count = 0;
  double sum = 0;
  
  while (inFile >> value)  // read a double value from the file until end of 
                        // the file is reached and the extraction operator >>
                        // returns false
  {
     cout << value << endl;
     if(max <= value)
      max = value;
     if(min >= value)
      min = value;
     sum += value;
     count++;
  }
   
   out_result << "Average = " << sum/count << endl;
   out_result << "Maximun = " << max << endl;
   out_result << "Minimun = " << min << endl;

}

