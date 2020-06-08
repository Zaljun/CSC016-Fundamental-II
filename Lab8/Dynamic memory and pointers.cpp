#include <iostream>
#include <string>

using namespace std;

int findSpace(const string &s);
void extract_words(const string &sentence, string *ptr_words);
void display(string *ptr_s, int nr);

int main()
{
	string s = "Oh captain, my captain, our fearful trip has done.";	
	//cout << findSpace(s);
	int nr_word;
	nr_word = 1 + findSpace(s);
	string *ptr_string = new string[nr_word];
	//cout << ptr_string;
	extract_words(s,ptr_string);
	display(ptr_string,nr_word);
}

int findSpace(const string &s)
{
	if(s.find(' ') == string::npos)
	    return 0;
	else
		return 1 + findSpace(s.substr(s.find(' ')+1));
}

void extract_words(const string &sentence, string *ptr_words)
{
	// use s.substr(ind_start, length) to extract
	// ind_start = 0 if use recursion
	// length = s.find(' ') - ind_start
	// can't find the last word since it ends with '.'
	if(sentence.find(' ') == string::npos)
	{
		*ptr_words = sentence.substr(0,sentence.find('.'));
	}
	else
	{
		*ptr_words = sentence.substr(0,sentence.find(' '));
		extract_words(sentence.substr(sentence.find(' ')+1),ptr_words+1);
	}
}

void display(string *ptr_s, int nr)
{
	for(int i = 0; i < nr; i++)
	  cout << ptr_s[i] << endl;
}

/*
Sample:
Oh
captain,
my
captain,
our
fearful
trip
has
done
*/
