// Maze.h
// load maze, set start and end
// record visited spots 
// create possible qualified moves(unvisited)
// find path
// display path
#include <iostream>
#include "MazeNode.h"
#include <string>
#include <list>
#include <stack>
#include <cassert>
#include <fstream>

using namespace std;

#ifndef MAZE
#define MAZE

const int SIZE = 10;

class Maze
{
	private:
	    
	    int maze[SIZE][SIZE];                // load the maze
	    int startX, startY, endX, endY;      // set start and end
	    list<MazeNode*> visited;             // container for visited spots
	    MazeNode *endNode;              // initialized by findPath - the end node of the solution or 0 if a 
	                                    // solution was not found

	    stack<MazeNode*> unvisited;          // container for unvisited possible spots when moving
	public:
	    Maze();
	    Maze(string fileName, int startX, int startY, int endX, int endY); //set maze, start and end spots
	    void setMaze(string fileName);       // set the maze
	    void setStart(int startX, int startY); 
	    void setEnd(int endX, int endY);
	    int getStartX() const;            // return start spot
	    int getStartY() const;
	    int getEndX() const;              // return end spot
	    int getEndY() const;
	    bool isEnd(MazeNode *curr);       // check if current is at end spot, compare its x and y
	                                      // return true when it reachs the end
	    void findPath();                  // find path
	    void displayPath() const;         // display from the end to the start
	    bool isVisited(MazeNode *curr);   // check if next possible move is visited
	                                      // return true when it is visited
	    void addPossibleMove(MazeNode *curr);// allocate dynamic memory for all spots around 
                                             // current that are free and have not been visited before
                                             // then add them on the unvisited stack

};

#endif
