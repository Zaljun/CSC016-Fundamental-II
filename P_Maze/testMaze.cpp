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
