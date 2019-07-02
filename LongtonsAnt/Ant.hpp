#ifndef ANT_HPP
#define ANT_HPP

class Ant
{
public:
	Ant(int row, int col);
	~Ant();
	int getXPosition();
	int getYPosition();
	char getOrientation();
	void setNewXPosition(int);
	void setNewYPosition(int);
	void setNewOrientation(char);

private:
	int xPosition;
	int yPosition;
	char antDir;
};

#endif