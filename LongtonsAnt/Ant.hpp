#ifndef ANT_HPP
#define ANT_HPP

class Ant
{
public:
	enum Direction
	{
		NORTH, WEST, SOUTH, EAST
	};

	Ant();
	Ant(int row, int col);
	~Ant();
	int getXPosition();
	int getYPosition();
	void setNewXPosition();
	void setNewYPosition();
	void setNewOrientation();
	int getOrientation();
	//Direction direction;

private:
	int xPosition;
	int yPosition;
	Direction antDirection;
};

#endif