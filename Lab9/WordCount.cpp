#include "WordCount.h"

WordCount::WordCount(word = "", count = 0)
{
	word = word;
	count = count;
}

void WordCount::set_word(const string &new_word)
{
	word = new_word;
}

void WordCount::add_count()
{
	count++;
}

void WordCount::set_count(int new_count)
{
	count = new_count;
}

string WordCount::get_word()
{
	return word;
}

int WordCount::get_count()
{
	return count;
}

bool WordCount::operator<(const WordCount &other)
{
	if(count < other.count)
	  return true;
	else
	  return false;
}        
