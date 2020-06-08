#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>

using namespace std;

#ifndef MONEY
#define MONEY

class Money
{
	private:
	  int dollars;
	  int cents;
	public:
	  //Constructor (default & specifc)
	  Money();
	  Money(int dollars, int cents);
	  //Operations
	  void add(int add_dollars, int add_cents);
	  void add(const Money &add_money);
	  void sub(int sub_dollars, int sub_cents);
	  void sub(const Money &sub_money);
	  //Fundemental Functions
	  void display() const;
	  string to_string() const;
	  //returns the amount of dollars and cents
	  int get_dollars() const;
	  int get_cents() const;
	  bool isBigger(const Money &other) const;
	  
};

#endif
