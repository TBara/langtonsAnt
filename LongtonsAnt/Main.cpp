#include <iostream>
#include <string>
#include "Ant.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool inputValidInt(std::string, int&);
void printBoard(char** array, int rows, int cols);
int antMove(Ant);

int main()
{
	int initialX = 0;
	int initialY = 0;
	int rows = 0;
	int columns = 0;
	int steps = 0;
	int userInput = 0;

	do
	{
		inputValidInt("Press 1 to start Langton Ant simulation or press 2 to exit the program", userInput);
	} while (userInput != 1 && userInput != 2);


	if (userInput == 1)
	{
		cout << "You chose to continue the program. You entered: " << userInput << endl;
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
		
		//Create array of arrays and set all fields to blank space
		char** arr = new char* [rows];
		for (int i = 0; i < rows; i++)
		{
			arr[i] = new char[columns];
			for (int j = 0; j < columns; j++)
			{
				if (i == initialY && j == initialX)
				{
					arr[initialY][initialX] = '*';
				}
				else
				{
					arr[i][j] = '_';
				}
			}
		}

		//Print the board
		printBoard(arr, rows, columns);

		//Instantiate ant
		Ant ant(initialY, initialX);
		cout << "Orientation is a type: " << typeid(ant.getOrientation()).name() << endl;
		cout << "xPosition is a type: " << typeid(ant.getXPosition()).name() << endl;
		cout << "yPosition is a type: " << typeid(ant.getYPosition()).name() << endl;
		
		for (int i = 0; i <= steps; i++)
		{
			
		}
		
	}

	cin.ignore();
	cin.get();
	return 0;
}

int antMove(Ant ant)
{
	return ant.getOrientation();
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
			if (floor(integer) == ceil(integer) && integer > 0)
			{
				validInt = true;
				userInp = integer;
			}
		}
	} while (!validInt);
	return validInt;
}

void printBoard(char** array, int rows, int cols)
{
	//Referenced codereview.stackexchange.com/questions/51716/shortest-possible-way-of-printing-a-specific-board
	string border = "";
	border.assign(cols + 2, '_');
	cout << border << endl;

	for (int i = 0; i < rows; i++) {

		cout << "|" << array[i][0];

		for (int j = 1; j < cols; j++) {
			cout << array[i][j];
		}

		cout << "|" << endl;
	}
	cout << border << endl;
}