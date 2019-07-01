#include "Ant.hpp"
//Default constructor
Ant::Ant()
{
	xPosition = 0;
	yPosition = 0;
}

//Parameterized Constructor 
Ant::Ant(int rowPos, int colPos)
{
	xPosition = colPos;
	yPosition = rowPos;
	antDirection = SOUTH;
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

int Ant::getOrientation()
{
	return antDirection;
}

void Ant::setNewXPosition()
{

}

void Ant::setNewYPosition()
{

}

void Ant::setNewOrientation()
{

}
