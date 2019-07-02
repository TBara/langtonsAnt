#include "Ant.hpp"

//Parameterized Constructor 
Ant::Ant(int rowPos, int colPos)
{
	xPosition = colPos;
	yPosition = rowPos;
	antDir = 'W';
}

//Destructor
Ant::~Ant()
{

}

int Ant::getXPosition()
{
	return xPosition;
}

int Ant::getYPosition()
{
	return yPosition;
}

char Ant::getOrientation()
{
	return antDir;
}

void Ant::setNewXPosition(int newX)
{
	xPosition = newX;
}

void Ant::setNewYPosition(int newY)
{
	yPosition = newY;
}

void Ant::setNewOrientation(char newOrientation)
{
	antDir = newOrientation;
}
