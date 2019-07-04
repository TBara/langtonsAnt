/*********************************************************************
** Program name: Langton's Ant
** Author: Tom Barabasz
** Date: 07/04/2019
** Description: This file contains function definitions for the Ant class
*********************************************************************/
#include "Ant.hpp"

//Parameterized Constructor 
Ant::Ant(int rowPos, int colPos, char orientation)
{
	xPosition = colPos;
	yPosition = rowPos;
	antDir = orientation;
}

//Destructor
Ant::~Ant(){}

//Get column position
int Ant::getXPosition()
{
	return xPosition;
}

//Get row position
int Ant::getYPosition()
{
	return yPosition;
}

//Get ant's directtion of travel
char Ant::getOrientation()
{
	return antDir;
}

//Set ant's new column position
void Ant::setNewXPosition(int newX)
{
	xPosition = newX;
}

//Set ant's new row position
void Ant::setNewYPosition(int newY)
{
	yPosition = newY;
}

//Set ant's new direction of travel
void Ant::setNewOrientation(char newOrientation)
{
	antDir = newOrientation;
}

/*********************************************************************
					moveEW
This function takes Ant class and two integers as parameters to
move the ant in East or West direction. It eveluates ant's current
position. If the ant's move will put it off the board, the ant is
placed on opposite end.
*********************************************************************/
int Ant::moveEW(Ant ant, int increment, int columns)
{
	int currentXPos = ant.getXPosition();
	int newXPos = currentXPos + increment;
	if (newXPos > columns - 1)
	{
		newXPos = 0;
	}
	else if (newXPos < 0)
	{
		newXPos = columns - 1;
	}
	return newXPos;
}


/*********************************************************************
					moveNS
This function takes Ant class and two integers as parameters to
move the ant in North or South direction. It eveluates ant's current
position. If the ant's move will put it off the board, the ant is
placed on opposite end.
*********************************************************************/
int Ant::moveNS(Ant ant, int increment, int rows)
{
	int newYPos = ant.getYPosition() + increment;
	if (newYPos > rows - 1)
	{
		newYPos = 0;
	}
	else if (newYPos < 0)
	{
		newYPos = rows - 1;
	}
	return newYPos;
}
