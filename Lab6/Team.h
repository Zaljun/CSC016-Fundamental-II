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
