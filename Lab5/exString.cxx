// ex strings 
#include <string>
#include <iostream>

using namespace std;

int count_vowels(string s);

int main()
{
    // example substr
    // Extract first and last name
    string name = "John Doe",
           first_name,
           last_name;
        
    cout << name << " has " << name.length() << " characters" << endl;
    
    // find the space --> ind_space
    // function find()
    size_t ind_space = name.find(' ');
    
    // string::npos = end of string
    if (ind_space != string::npos)  // ' ' was found in name
    {
        // first name = substring from index 0 to ind_space-1
        first_name = name.substr(0, ind_space);
        // last name  = substring from index ind_space+1 to end
        last_name  = name.substr(ind_space+1); // until the end
        
        cout << "First name " << first_name << endl;
        cout << "Last name " << last_name << endl;
    }
    
    // test extract vowels
    cout << name << " has " << count_vowels(name) << " vowels" << endl;
    
}

// recursive function to count # of vowels in a string
int count_vowels(string s)
{
    if (s.length() == 0)  // base case
        return 0;
    else // recursive case
    {
        // process s[0]
        int vowel = 0;
        string all_vowels = "aAiIeEoOuU";
        if (all_vowels.find(s[0]) != string::npos)
            vowel++;
        // extract substring from index 1 to end 
        // call function count_vowels on substring
        return vowel + count_vowels(s.substr(1));
    }
}


