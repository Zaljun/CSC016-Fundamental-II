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
