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
	    MazeNode* getPrev() const; //return prev in order to link the path
};

#endif
