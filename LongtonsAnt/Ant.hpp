/*********************************************************************
** Program name: Langton's Ant
** Author: Tom Barabasz
** Date: 07/04/2019
** Description: This file contains the Ant class definition.
*********************************************************************/
#ifndef ANT_HPP
#define ANT_HPP

class Ant
{
public:
	//Constructor
	Ant(int row, int col, char orientation);

	//Destructor
	~Ant();

	//Getter functions
	int getXPosition();
	int getYPosition();
	char getOrientation();

	//Setter functions
	void setNewXPosition(int);
	void setNewYPosition(int);
	void setNewOrientation(char);
	
	//Moves the ant East / West
	int moveEW(Ant ant, int increment, int columns);
	//Moves the ant North / South 
	int moveNS(Ant ant, int increment, int rows);

private:
	int xPosition;
	int yPosition;
	char antDir;
};

#endif