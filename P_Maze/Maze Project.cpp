//MazeNode.h
//basic element to present spot and track moves in the maze
#include <iostream>

#ifndef MAZENODE
#define MAZENODE
class MazeNode
{
	private:
	    int x, y;          // current location
	    MazeNode *prev;    // pointer to the previous node, prev = 0 if it is the beginning
	    int cost;          // number of moves from the beginning
	public:
	    MazeNode();
	    MazeNode(int xc, int yc, int costNew, MazeNode *prev_ptr);
	    int getX() const;
	    int getY() const;
	    int getCost() const;
	    void setX(int x_input);
	    void setY(int y_input);
	    
};

#endif

=================================================================================================
// MazeNode.cpp
#include "MazeNode.h"

using namespace std;

MazeNode::MazeNode()
{
	x = 0;
	y = 0;
	cost = 0;
	prev = 0;
}

MazeNode::MazeNode(int xc, int yc, int costNew, MazeNode *prev_ptr)
{
	x = xc;
	y = yc;
	cost = costNew;
	prev = prev_ptr;
}

int MazeNode::getX() const
{
	return x;
}

int MazeNode::getY() const
{
	return y;
}

int MazeNode::getCost() const
{
	return cost;
}

void MazeNode::setX(int x_input)
{
	x = x_input;
}

void MazeNode::setY(int y_input)
{
	y = y_input;
}


==============================================================================================
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
	    void displayPath() const;         // display from the start to the end
	    bool isVisited(MazeNode *curr);   // check if next possible move is visited
	                                      // return true when it is visited
	    void addPossibleMove(MazeNode *curr);// allocate dynamic memory for all spots around 
                                             // current that are free and have not been visited before
                                             // then add them on the unvisited stack

};

#endif

===========================================================================================================
//Maze.cpp
#include "Maze.h"
#include <fstream>
#include <cstdlib>
using namespace std;

Maze::Maze()
{
	startX = 0;
	startY = 0;
	endX   = SIZE - 1;
	endY   = SIZE - 1;
	//visited is empty
	endNode = 0;
	//unvisited is empty
}

Maze::Maze(string fileName, int start_X, int start_Y, int end_X, int end_Y)
{
	setMaze(fileName);
	startX = start_X;
	startY = start_Y;
	endX   = end_X;
	endY   = end_Y;
}

void Maze::setMaze(string fileName)
{
	ifstream inputFile;
	inputFile.open("myMaze.txt");
	for (int row = 0; row < SIZE; row++)
    {
     	for (int col = 0; col < SIZE; col++)  
     	 	inputFile >> maze[row][col]; 
    }
    // display maze on the screen
	for (int row = 0; row < SIZE; row++)
	{
	 	for (int col =0; col < SIZE; col++)
	 		cout << maze[row][col];
	 	cout << endl; 
	 }	
}

void Maze::setStart(int start_X, int start_Y)
{
	startX = start_X;
	startY = start_Y;
}

void Maze::setEnd(int end_X, int end_Y)
{
	endX = end_X;
	endY = end_Y;
}

int Maze::getStartX() const
{
	return startX;
}

int Maze::getStartY() const
{
	return startY;
}

int Maze::getEndX() const
{
	return endX;
}

int Maze::getEndY() const
{
	return endY;
}

bool Maze::isEnd(MazeNode *curr)       //return true if current reaches the end
{
	if(curr->getX() == endX)
	    if(curr->getY() == endY)
	        return true;
	return false;
}

void Maze::findPath()
{
	MazeNode *start = new MazeNode(startX,startY,0,0);
	MazeNode *current = start;
	addPossibleMove(current);          //make the first step
	bool done = false;
	while(isEnd(current) != true && done != true)
	{
		visited.push_front(current);   //add current on visited list
		addPossibleMove(current);      //find possible moves
		if(!unvisited.empty())         //return true if there are still qualified moves
		{
			current = unvisited.top(); //use the move and put it into visited list after using
			unvisited.pop();
		}
		else
			done = true;               //there is no way to go
	}
	if(!done)
		endNode = current;             
	else
	    endNode = 0;                
}

void Maze::displayPath() const
{
	list<MazeNode*>::const_iterator i;
	for(i = visited.begin(); i != visited.end(); i++)
	{
		cout << "(" << (*i)->getX() << "," << (*i)->getY() << ")" << endl;
		cout << "current cost: " << (*i)->getCost() << endl;
	}
}

bool Maze::isVisited(MazeNode *curr)    //returns true if the curr MazeNode is in the visited list 
{                                       //(search in the visited list if the same location was stored
	list<MazeNode*>::iterator i;
	for(i = visited.begin(); i != visited.end(); i++)
	{
		if(curr->getX() == (*i)->getX())
		    if(curr->getY() == (*i)->getY())         //traverse the list. if its x and y are found in the list, 
		        return true;            //return true
	}
	return false;
}

void Maze::addPossibleMove(MazeNode *curr)
{
	assert(curr->getX() >= 0 && curr->getX() <= SIZE-1);
	assert(curr->getY() >= 0 && curr->getY() <= SIZE-1);
	int xc, yc, costc;
	xc = curr->getX();
	yc = curr->getY();
	costc = curr->getCost();
	if(maze[xc+1][yc] == 0)          //move down
	{
		MazeNode *down = new MazeNode(xc+1,yc,costc+1,curr);       //allocate dynamic memory for next location
		
		if(!isVisited(down))                   //check if it is visited
		    unvisited.push(down);
	}   
	if(maze[xc-1][yc] == 0)          //move up
	{
		MazeNode *up = new MazeNode(xc-1,yc,costc+1,curr);         //allocate dynamic memory for next location
		
		if(!isVisited(up))                     //check if it is visited
		    unvisited.push(up);
	}   
	if(maze[xc][yc+1] == 0)          //move right
	{
		MazeNode *right = new MazeNode(xc,yc+1,costc+1,curr);       //allocate dynamic memory for next location
		
		if(!isVisited(right))                   //check if it is visited
		    unvisited.push(right);
	}
	if(maze[xc][yc-1] == 0)          //move left
	{
		MazeNode *left = new MazeNode(xc,yc-1,costc+1,curr);       //allocate dynamic memory for next location
		
		if(!isVisited(left))                   //check if it is visited
		    unvisited.push(left);
	}   
	if(maze[xc+1][yc+1] == 0)          //move down_right
	{
		MazeNode *dn_rt = new MazeNode(xc+1,yc+1,costc+1,curr);       //allocate dynamic memory for next location
	
		if(!isVisited(dn_rt))                   //check if it is visited
		    unvisited.push(dn_rt);
	} 
	if(maze[xc+1][yc-1] == 0)          //move down_left
	{
		MazeNode *dn_lf = new MazeNode(xc+1,yc-1,costc+1,curr);       //allocate dynamic memory for next location
	;
		if(!isVisited(dn_lf))                   //check if it is visited
		    unvisited.push(dn_lf);
	}   
	if(maze[xc-1][yc+1] == 0)          //move up_right
	{
		MazeNode *up_rt = new MazeNode(xc-1,yc+1,costc+1,curr);       //allocate dynamic memory for next location
	
		if(!isVisited(up_rt))                   //check if it is visited
		    unvisited.push(up_rt);
	}          
	if(maze[xc-1][yc-1] == 0)          //move up_left
	{
		MazeNode *up_lf = new MazeNode(xc-1,yc-1,costc+1,curr);       //allocate dynamic memory for next location
		
		if(!isVisited(up_lf))                   //check if it is visited
		    unvisited.push(up_lf);
	}          
}

===========================================================================================================
//testMaze.cpp
#include "MazeNode.h"
#include "Maze.h"

using namespace std;

int main()
{
	Maze maze("myMaze.txt",0,0,9,9);
	cout << "Start: " << maze.getStartX() << "," << maze.getStartY() << endl;
	cout << "End: " << maze.getEndX() << "," << maze.getEndY() << endl;
	//test MazeNode class
	MazeNode node1(8,9,0,0);
	cout << node1.getX() << node1.getY() << node1.getCost() << endl;
	MazeNode *node1_ptr = &node1;
	cout << maze.isEnd(node1_ptr) << endl;  //test isEnd() in Maze class
	node1_ptr->setX(9);                   	//change test node to be (9,9)        
    cout << node1.getX() << node1.getY() << node1.getCost() << endl;
    cout << maze.isEnd(node1_ptr) << endl;
	maze.findPath();
	maze.displayPath();
	cout << "ojbk";
}

/*Sample:
0 1 0 0 1 0 0 1 0 0
0 0 1 1 1 0 0 0 0 1
1 0 1 0 1 0 1 0 1 0 
0 0 0 0 1 0 1 0 1 0 
0 0 0 1 0 0 1 0 1 0 
1 1 0 0 0 0 1 0 1 0 
1 1 1 1 1 0 0 0 1 0 
0 0 0 0 0 1 0 0 0 0 
1 1 1 1 1 1 0 1 0 0
0 0 0 0 0 0 0 1 1 0 
Start: 0,0
End: 9,9
890
0
990
1
Assertoin Failed!
*/


