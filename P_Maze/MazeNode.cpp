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

MazeNode* MazeNode::getPrev() const
{
	return prev;
}
