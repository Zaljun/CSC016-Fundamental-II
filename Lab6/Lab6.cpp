//Team.h
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstring>

using namespace std;

#ifndef TEAM
#define TEAM

class Team
{
	private:
	  string name;
	  int nr_player;
	  int nr_wins;
	  int nr_losses;
	  
	public:
	  Team();
	  //Specific: Call setTeam() function
	  //Assert nr_player & nr_wins & nr_losses
	  Team(const string newName, int newPlayer, int wins, int losses);
	  void display();
	  void addWins();
	  void addWins(int add_wins);
	  void addLosses();
	  void addLosses(int add_losses);
	  void addPlayer(int nrPlayer);
	  void delPlayer(int nrPlayer);
	  //call this in the specific constructor
	  void setTeam(string newName, int newPlayer, int wins, int losses);
	  bool isBetter(const Team &other);
	  int getWins();
	  int getLosses();
	  int getPoints();
};

#endif


//
//Team.cpp
#include "Team.h"

//hofstra basketball team
Team::Team()
{
	name = "Hello World";
	nr_player = 5;
	nr_wins   = 0;
	nr_losses = 0;
}

Team::Team(const string newName,int newPlayer, int wins, int losses)
{
	setTeam(newName,newPlayer,wins,losses);
}

void Team::display()
{
	cout << "Team '" << name << "' has " << nr_player << " players" << endl;
	cout << nr_wins << " Wins; " << nr_losses << " Losses" << endl;
}

void Team::addWins()
{
	nr_wins += 1;
}

void Team::addWins(int add_wins)
{
	assert(add_wins >= 0);
	nr_wins += add_wins;
}

void Team::addLosses()
{
	nr_losses += 1;
}

void Team::addLosses(int add_losses)
{
	assert(add_losses >= 0);
	nr_losses += add_losses;
}

void Team::addPlayer(int nrPlayer)
{
	assert(nrPlayer >= 0);
	nr_player += nrPlayer;
}

void Team::delPlayer(int nrPlayer)
{
	assert(nr_player >= nrPlayer);
	nr_player -= nrPlayer;
}

void Team::setTeam(string newName, int newPlayer, int wins, int losses)
{
	assert(newPlayer > 0 && wins >= 0 && losses >= 0);
	name = newName;
	nr_player = newPlayer;
	nr_wins   = wins;
	nr_losses = losses;
}

bool Team::isBetter(const Team &other)
{
	if(nr_wins - nr_losses > other.nr_wins - other.nr_losses)
	  {
		  cout << "Better" << endl;
		  return true;
	  }
	else if(nr_wins - nr_losses < other.nr_wins - other.nr_losses)
	  {
		  cout << "Not better" << endl;
		  return false;
	  }
	else
	      cout << "The points are equal." << endl;
}

int Team::getWins()
{
	return nr_wins;
}

int Team::getLosses()
{
	return nr_losses;
}

int Team::getPoints()
{
	return nr_wins - nr_losses;
}


//
//testTeam.cpp
#include "Team.h"

int main()
{
	Team team1;
	team1.display();
	team1.addWins();
	team1.addWins(2);
	team1.display();
	team1.addLosses();
	team1.addLosses(2);
	team1.addPlayer(3);
	team1.delPlayer(2);
	team1.display();
	Team team2("CS16",6,4,4);
	team2.display();
	team2.isBetter(team1);
	cout << team1.getWins() << " " << team1.getLosses() << endl;
	cout << "Points of team1: " << team1.getPoints() << endl;
	team2.addWins();
	team2.addPlayer(3);
	team2.display();
	team2.isBetter(team1);
	team2.addLosses(2);
	team2.delPlayer(1);
	team2.display();
	team2.isBetter(team1);
}

/*
Sample
Team 'Hello World' has 5 players
0 Wins; 0 Losses
Team 'Hello World' has 5 players
3 Wins; 0 Losses
Team 'Hello World' has 5 players
3 Wins; 3 Losses
Team 'CS16' has 6 players
4 Wins; 4 Losses
The points are equal.
3 3
Points of team1: 0
Team 'CS16' has 9 players
5 Wins; 4 Losses
Better
Team 'CS16' has 8 players
5 Wins; 6 Losses
Not Better
*/


//
//Money.h
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


//
//Money.cpp
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


//
//testMoney.cpp
#include "Money.h"

int main()
{
	Money money1;
	Money money2(2,3);
	money1.display();
	money2.display();
	money1.add(9,99);
	money1.display();
	money1.add(money2);
	money1.display();
	money1.sub(0,50);
	money1.display();
	money1.sub(money2);
	money1.display();
	money1.isBigger(money2);
	cout << money1.to_string();
}

/*
Sample
Default constructor
Specific constructor
$0.0
$2.3
$9.99
$12.2
$11.52
$9.49
Yes
$9.49
*/


//
//Account.h
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
};

#endif


//
//Account.cpp
#include "Account.h"

Account::Account()
{
	create_id();
}

Account::Account(int start_dollars, int start_cents)
{
	assert(start_dollars >= 0 && start_cents >= 0);
	amount.add(start_dollars,start_cents);
	create_id();
}

void Account::create_id()
{
	for(int i=0; i<10; i++)
	{
		int digit = rand()%10;
		char char_digit = '0' + digit;
		account_id += char_digit;
	}
}

void Account::withdraw(int minus_dollars, int minus_cents)
{
	assert(minus_dollars*100+minus_cents <= 100*amount.get_dollars()+amount.get_cents());
	amount.sub(minus_dollars,minus_cents);
}

void Account::deposit(int add_dollars, int add_cents)
{
	amount.add(add_dollars,add_cents);
}

void Account::transfer_into(Account &destination, const Money &tr_amount)
{
	assert(amount.isBigger(tr_amount));
	destination.amount.add(tr_amount);
	amount.sub(tr_amount);
}

void Account::transfer_from(Account &source, const Money &tr_amount)
{
	assert(source.amount.isBigger(tr_amount));
	source.amount.sub(tr_amount);
	amount.add(tr_amount);
}

bool Account::is_valid(int sub_dollars, int sub_cents)
{
	if(sub_dollars*100+sub_cents <= amount.get_dollars()*100+amount.get_cents())
	{
		return true;
		cout << "Valid" << endl;
	}
	else
	{
		return false;
		cout << "Not Valid" << endl;
	}
}

bool Account::is_valid(const Money &sub_amount)
{
	if(sub_amount.get_dollars()*100+sub_amount.get_cents() <= amount.get_dollars()*100+amount.get_cents())
	{
		return true;
		cout << "Valid" << endl;
	}
	else
	{
		return false;
		cout << "Not Valid" << endl;
	}
}


//
//testAccount.cpp
#include "Account.h"

int main()
{
	Account acc1;
	Account acc2(12,68);
	acc2.withdraw(1,99);
	acc2.deposit(3,14);
	Money transfer(7,23);
	acc2.is_valid(transfer);
	acc2.transfer_into(acc1,transfer);
	acc2.is_valid(1,12);
	acc2.transfer_from(acc1,transfer);
}

/*
Sample
errors:
C:\Users\admin\AppData\Local\Temp\ccmE4e5r.o:testAccount.cpp:(.text+0x7a): undefined reference to 'Money::Money(int, int)'
C:\Users\admin\AppData\Local\Temp\ccaGq4Is.o:Account.cpp:(.text+0x1a): undefined reference to 'Money::Money()'
C:\Users\admin\AppData\Local\Temp\ccaGq4Is.o:Account.cpp:(.text+0x81): undefined reference to 'Money::Money()'
C:\Users\admin\AppData\Local\Temp\ccaGq4Is.o:Account.cpp:(.text+0xce): undefined reference to 'Money::add(int, int)'
*/


//revised version
//testAccount.cpp
#include "Account.h"

int main()
{
	Account acc1;
	Account acc2(12,68);
	acc1.display();
	acc2.display();
	
	acc2.withdraw(1,99);
	acc2.display();
	acc2.deposit(3,14);
	acc2.display();
	
	Money transfer(7,23);
	acc2.is_valid(transfer);
	acc2.transfer_into(acc1,transfer);
	acc1.display();
	acc2.display();
	acc2.is_valid(1,12);
	acc2.transfer_from(acc1,transfer);
	acc1.display();
	acc2.display();
	
}

/*
Sample:
Default constructor
Default constructor
ID: 1740948824
$0.0
ID: 5517115276
$12.68
ID: 5517115276
$10.69
ID: 5517115276
$13.83
Specific constructor
ID: 5517115276
$13.83
Yes
ID: 1740948824
$7.23
ID: 5517115276
$6.60
Yes
ID: 1740948824
$0.0
ID: 5517115276
$13.83
*/
