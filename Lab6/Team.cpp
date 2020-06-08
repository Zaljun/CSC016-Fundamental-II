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
