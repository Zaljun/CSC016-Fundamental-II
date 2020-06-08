#include <iostream>
#include <cstring>
#include <cassert>
#include "Money.h"

using namespace std;

#ifndef ACCOUNT
#define ACCOUNT

class Account
{
	private:
	  Money amount;
	  string account_id;
	public:
	  //constructor
	  Account();
	  Account(int start_dollars, int start_cents);
	  void withdraw(int minus_dollars, int minus_cents);
	  void deposit(int add_dollars, int add_cents);
	  void transfer_into(Account &destination, const Money &tr_amount);
	  void transfer_from(Account &source, const Money &tr_amount);
	  bool is_valid(int sub_dollars, int sub_cents);
	  bool is_valid(const Money &sub_amount);
	  void create_id();
	  void display();
};

#endif
