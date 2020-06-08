#include <iostream>
#include <string>

using namespace std;

string toUpper(string s);

int main()
{
	string input,turned;
	getline(cin,input);
	turned = toUpper(input);
	cout << turned;
}

string toUpper(string s)
{
	if(s.length() == 0)
	  return "";
	else
	{
		s[0] = toupper(s[0]);
		return s[0] + toUpper(s.substr(1));
	}
}
