#include "Money.h"

Money::Money()
{
	cout << "Default constructor" << endl;
	dollars = 0;
	cents = 0;
}

Money::Money(int new_dollars, int new_cents)
{
	assert(new_dollars >= 0 && new_cents >= 0 && new_cents <= 100);
	cout << "Specific constructor" << endl;
	dollars = new_dollars;
	cents = new_cents;
}

void Money::add(int add_dollars, int add_cents)
{
	dollars += add_dollars;
	cents   += add_cents;
	if(cents >= 100)
	{
		dollars += cents / 100;
		cents = cents % 100;
	}
}

void Money::add(const Money &add_money)
{
	dollars += add_money.dollars;
	cents   += add_money.cents;
	if(cents >= 100)
	{
		dollars += cents / 100;
		cents = cents % 100;
	}
}

void Money::sub(int sub_dollars, int sub_cents)
{
	assert(dollars*100+cents >= sub_dollars*100+sub_cents);
	dollars -= sub_dollars;
	cents   -= sub_cents;
	if(cents  < 0)
	{
		dollars -= 1;
		cents += 100;
	}
}

void Money::sub(const Money &sub_money)
{
	assert(dollars*100+cents >= sub_money.get_dollars()*100+sub_money.get_cents());
	dollars -= sub_money.dollars;
	cents   -= sub_money.cents;
	if(cents  < 0)
	{
		dollars -= 1;
		cents += 100;
	}
}

void Money::display() const
{
	cout << "$" << dollars << "." << cents << endl;
}

string Money::to_string() const
{
	string str_money;
	ostringstream convert;
	convert << '$' << dollars << '.' << cents;
	str_money = convert.str();
	return str_money;
}

int Money::get_dollars() const
{
	return dollars;
}

int Money::get_cents() const
{
	return cents;
}

bool Money::isBigger(const Money &other) const
{
	if(100*dollars + cents >= 100*other.dollars + other.cents)
	  {
		  cout << "Yes" <<endl;
		  return true;
	  }
	else
	  {
		  cout << "No" << endl;
		  return false;
	  }
}
