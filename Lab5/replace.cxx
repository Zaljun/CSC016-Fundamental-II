#include <iostream>
#include <string>

using namespace std;

string replaceChar(string s, char orig, char rplc);

int main()
{
	string input,output;
	getline(cin,input);	
	char original, replace;
	cout << "The letter you want to replace: ";
	cin >> original;
	cout << " The new letter is:  ";
	cin >> replace;
	output = replaceChar(input,original,replace);
	cout << output;
}

string replaceChar(string s, char orig, char rplc)
{
	if(s.length() == 0)
	  return "";
	else
	{
		if(s[0] == orig)
		{
			s[0] = rplc;
		}
		return s[0] + replaceChar(s.substr(1),orig,rplc);
	}
}
