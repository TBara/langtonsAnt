#ifndef ANT_HPP
#define ANT_HPP

class Ant
{
private:
	int xPosition;
	int yPosition;
	int antDirection;

	enum Direction
	{
		NORTH, WEST, SOUTH, EAST
	};

public:
	Ant();
	~Ant();
	void getPosition();
	void getOrientation();
	void setNewPosition();
	void setNewOrientation();
	Direction dir;
};

#endif