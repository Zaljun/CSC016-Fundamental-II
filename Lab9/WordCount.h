// WordCount Class declaration
// describe objects that can hold a word (string) and its count (int)

#include <string>
#include <iostream>
using namespace std;

#ifndef
#define WORDCOUNT

class WordCount{
    private: 
        string word;
        int count;
    public:
        WordCount(word = "", count = 0); 
        void set_word(const string &new_word);
        void add_count();  // add 1 to the count
        void set_count(int new_count);
        string get_word(); // returns word
        int get_count();   // returns count
        bool operator<(const WordCount &other);  // need this function for
        // sorting 
        // compares two WordCount objects and returns true if count < other.count
};

#endif
