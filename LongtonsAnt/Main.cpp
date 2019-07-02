#include <iostream>
#include <string>
#include "Ant.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool inputValidInt(std::string, int&);
void printBoard(char** array, int rows, int cols, Ant ant);
int moveNS(Ant ant, int, int);
int moveEW(Ant ant, int, int);
void changeSpCol(char** array, int, int);

int main()
{
	int initialX = 0;
	int initialY = 0;
	int rows = 0;
	int columns = 0;
	int steps = 0;
	int userInput = 0;
	char spColor = '_';

	do
	{
		inputValidInt("Press 1 to start Langton Ant simulation or press 2 to exit the program", userInput);
	} while (userInput != 1 && userInput != 2);


	if (userInput == 1)
	{
		inputValidInt("Enter number of rows on the board", rows);
		inputValidInt("Enter number of columns on the board", columns);
		inputValidInt("Enter number of steps the ant will take", steps);

		//Get ant's initial position
		do
		{
			inputValidInt("Enter ant's initial row number. ", initialY);
			inputValidInt("Enter ant's initial column number", initialX);
			if ((initialY > columns) || (initialX > rows))
			{
				cout << "The ant can't be placed there." << endl;
			}
		} while ((initialY > columns) || (initialX > rows) || (initialY < 0) || (initialX < 0));

		//Instantiate ant
		Ant ant(initialY, initialX);
		
		//Create array of arrays and set all fields to blank space
		char** arr = new char* [rows];
		for (int i = 0; i < rows; i++)
		{
			arr[i] = new char[columns];
			for (int j = 0; j < columns; j++)
			{
				arr[i][j] = spColor;
			}
		}
		
		//print board
		printBoard(arr, rows, columns, ant);

		//move the ant
		for (int i = 0; i <= steps; i++)
		{
			int xPos = ant.getXPosition();
			int yPos = ant.getYPosition();
			char orientation = ant.getOrientation();
			char spaceColor = arr[yPos][xPos];

			cout << "Ant's current1 position is " << ant.getXPosition() << " " << ant.getYPosition() << endl;
			//antMove(ant, rows, columns, arr);
			//printBoard(arr, rows, columns, ant);
			cout << "Space color is: " << spaceColor << endl;
			if (spaceColor == '_')
			{
				switch (orientation)
				{
				case 'N':
					ant.setNewOrientation('E');
					changeSpCol(arr, xPos, yPos);
					ant.setNewXPosition(moveEW(ant, 1, columns));
					break;
				case 'E':
					ant.setNewOrientation('S');
					changeSpCol(arr, xPos, yPos);
					ant.setNewYPosition(moveNS(ant, 1, rows));
					break;
				case 'S':
					ant.setNewOrientation('W');
					changeSpCol(arr, xPos, yPos);
					ant.setNewXPosition(moveEW(ant, -1, columns));
					break;
				case 'W':
					ant.setNewOrientation('N');
					changeSpCol(arr, xPos, yPos);
					ant.setNewYPosition(moveNS(ant, -1, rows));
					break;
				default:
					break;
				}
			}
			else if (spaceColor == '#')
			{
				switch (ant.getOrientation())
				{
				case 'N':
					ant.setNewOrientation('W');
					changeSpCol(arr, ant.getXPosition(), ant.getYPosition());
					ant.setNewXPosition(moveEW(ant, -1, columns));
					break;
				case 'E':
					ant.setNewOrientation('N');
					changeSpCol(arr, xPos, yPos);
					ant.setNewYPosition(moveNS(ant, -1, rows));
					break;
				case 'S':
					ant.setNewOrientation('E');
					changeSpCol(arr, xPos, yPos);
					ant.setNewXPosition(moveEW(ant, 1, columns));
					break;
				case 'W':
					ant.setNewOrientation('S');
					changeSpCol(arr, xPos, yPos);
					ant.setNewYPosition(moveNS(ant, 1, rows));
					break;
				default:
					break;
				}
			}
			cout << "Ant's current2 position is " << ant.getXPosition() << " " << ant.getYPosition() << endl;
			printBoard(arr, rows, columns, ant);
		}
		
	}

	cin.ignore();
	cin.get();
	return 0;
}

int moveEW(Ant ant, int increment, int columns)
{
	int currentXPos = ant.getXPosition();
	int newXPos = currentXPos  + increment;
	if (newXPos > columns -1)
	{
		newXPos = 0;
	}
	else if (newXPos < 0)
	{
		newXPos = columns - 1;
	}
	return newXPos;
}

int moveNS(Ant ant, int increment, int rows)
{
	int newYPos = ant.getYPosition() + increment;
	if (newYPos > rows -1)
	{
		newYPos = 0;
	}
	else if (newYPos < 0)
	{
		newYPos = rows - 1;
	}
	return newYPos;
}

void changeSpCol(char** arr, int row, int col)
{
	char spaceColor = arr[row][col];
	if (spaceColor == '_')
	{
		arr[row][col] = '#';
	} 
	else if (spaceColor == '#')
	{
		arr[row][col] = '_';
	}
}

bool inputValidInt(std::string question, int &userInp)
{
	bool validInt = false;
	float integer;
	do
	{
		cin.clear();
		cout << question << endl;
		cin >> integer;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid entry. Try again. " << endl;
		}
		else
		{
			if (floor(integer) == ceil(integer) && integer >= 0)
			{
				validInt = true;
				userInp = integer;
			}
		}
	} while (!validInt);
	return validInt;
}

void printBoard(char** array, int rows, int cols, Ant ant)
{
	//Referenced codereview.stackexchange.com/questions/51716/shortest-possible-way-of-printing-a-specific-board
	string border = "";
	border.assign(cols + 2, '_');
	cout << border << endl;

	for (int i = 0; i < rows; i++) {

		cout << "|" << array[i][0];

		for (int j = 1; j < cols-1; j++) {

			if (i == ant.getXPosition() && j == ant.getYPosition())
			{
				cout << '*';
			}
			else
			{
				cout << array[i][j];
			}
		}

		cout << "|" << endl;
	}
	cout << border << endl;
}