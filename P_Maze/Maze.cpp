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
	visited.push_front(current);
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
	MazeNode *ptr = endNode;
	while(ptr != 0)
	{
		cout << "(" << ptr->getX() << "," << ptr->getY() << ")" << endl;
		cout << "Current Cost: " << ptr->getCost() << endl;
		ptr = ptr->getPrev();
	}
	/*list<MazeNode*>::const_iterator i;
	for(i = visited.begin(); i != visited.end(); i++)
	{
		cout << "(" << (*i)->getX() << "," << (*i)->getY() << ")" << endl;
		cout << "current cost: " << (*i)->getCost() << endl;
	}*/
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
	if(xc+1>=0 && xc+1<=9 && yc>=0 && yc<=9)
	{
		if(maze[xc+1][yc] == 0 )          //move down
	    {
		    MazeNode *down = new MazeNode(xc+1,yc,costc+1,curr);       //allocate dynamic memory for next location
		
		    if(!isVisited(down))                   //check if it is visited
		        unvisited.push(down);
	    }   
	}
	if(xc-1>=0 && xc-1<=9 && yc>=0 && yc<=9)
	{
		if(maze[xc-1][yc] == 0 )          //move up
	    {
		    MazeNode *up = new MazeNode(xc-1,yc,costc+1,curr);       //allocate dynamic memory for next location
		
		    if(!isVisited(up))                   //check if it is visited
		        unvisited.push(up);
	    }   
	}
	if(xc>=0 && xc<=9 && yc+1>=0 && yc+1<=9)
	{
		if(maze[xc][yc+1] == 0 )          //move right
	    {
		    MazeNode *right = new MazeNode(xc,yc+1,costc+1,curr);       //allocate dynamic memory for next location
		
		    if(!isVisited(right))                   //check if it is visited
		        unvisited.push(right);
	    }   
	}
	if(xc>=0 && xc<=9 && yc-1>=0 && yc-1<=9)
	{
		if(maze[xc][yc-1] == 0 )          //move left
	    {
		    MazeNode *left = new MazeNode(xc,yc-1,costc+1,curr);       //allocate dynamic memory for next location
		
		    if(!isVisited(left))                   //check if it is visited
		        unvisited.push(left);
	    }   
	}
	if(xc+1>=0 && xc+1<=9 && yc+1>=0 && yc+1<=9)
	{
		if(maze[xc+1][yc+1] == 0 )          //move down_right
	    {
		    MazeNode *dn_rt = new MazeNode(xc+1,yc+1,costc+1,curr);       //allocate dynamic memory for next location
		
		    if(!isVisited(dn_rt))                   //check if it is visited
		        unvisited.push(dn_rt);
	    }   
	}
	if(xc+1>=0 && xc+1<=9 && yc-1>=0 && yc-1<=9)
	{
		if(maze[xc+1][yc-1] == 0 )          //move down_left
	    {
		    MazeNode *dn_lf = new MazeNode(xc+1,yc-1,costc+1,curr);       //allocate dynamic memory for next location
		
		    if(!isVisited(dn_lf))                   //check if it is visited
		        unvisited.push(dn_lf);
	    }   
	}
	if(xc-1>=0 && xc-1<=9 && yc+1>=0 && yc+1<=9)
	{
		if(maze[xc-1][yc+1] == 0 )          //move up_right
	    {
		    MazeNode *up_rt = new MazeNode(xc-1,yc+1,costc+1,curr);       //allocate dynamic memory for next location
		
		    if(!isVisited(up_rt))                   //check if it is visited
		        unvisited.push(up_rt);
	    }   
	}
	if(xc-1>=0 && xc-1<=9 && yc-1>=0 && yc-1<=9)
	{
		if(maze[xc-1][yc-1] == 0 )          //move up_left
	    {
		    MazeNode *up_lf = new MazeNode(xc-1,yc-1,costc+1,curr);       //allocate dynamic memory for next location
		
		    if(!isVisited(up_lf))                   //check if it is visited
		        unvisited.push(up_lf);
	    }   
	}
}
