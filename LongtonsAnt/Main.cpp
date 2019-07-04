/*********************************************************************
** Program name: Langton's Ant
** Author: Tom Barabasz
** Date: 07/04/2019
** Description: This program simulates Langton's Ant. The ant is placed 
	onto the board that is filled with white spaces, and starts moving forward.
	If the ant is on a white space, turn right 90 degrees and change the space to black.
	If the ant is on a black space, turn left 90 degrees and change the space to white.
*********************************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include "Ant.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::floor;
using std::ceil;
using std::string;
using std::rand;

bool inputValidInt(std::string, int&);
void menu(int*, string);
void printBoard(char** array, int rows, int cols, Ant ant);
void changeSpCol(char** array, int, int);
bool randStart(string, int &initX, int &initY, int rows, int columns);

const char BLANK_SPACE = ' ';

int main()
{
	//Memory leak check
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int initialX = 0;
	int initialY = 0;
	int rows = 0;
	int columns = 0;
	int steps = 0;
	int userInput = 0;
	char spColor = BLANK_SPACE;

	//Start menu
	menu(&userInput, "Press 1 to start Langton Ant simulation or press 2 to exit the program");

	//If the user wants to play
	if (userInput == 1)
	{	
		inputValidInt("Enter number of rows on the board", rows);
		inputValidInt("Enter number of columns on the board", columns);
		inputValidInt("Enter number of steps the ant will take", steps);

		if (!randStart("**Extra credit: Would you like the ant to start at a random location?\n Press 1 for Yes \n Press 2 for No \n", initialX, initialY, rows, columns))
		{
			//Get ant's initial position
			do
			{
				inputValidInt("Enter ant's initial row number. ", initialY);
				inputValidInt("Enter ant's initial column number", initialX);
				if ((initialY > columns - 1) || (initialX > rows - 1))
				{
					cout << "The ant can't be placed there." << endl;
				}
			} while ((initialY > columns - 1) || (initialX > rows - 1) || (initialY < 0) || (initialX < 0));
		}

		//Instantiate ant
		Ant ant(initialY, initialX, 'W');
		
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
		
		//print initial layout of the board
		printBoard(arr, rows, columns, ant);

		//move the ant
		for (int i = 0; i <= steps; i++)
		{
			int xPos = ant.getXPosition();
			int yPos = ant.getYPosition();
			char orientation = ant.getOrientation();
			char spaceColor = arr[yPos][xPos];

			cout << "Ant's current1 position is " << ant.getXPosition() << " " << ant.getYPosition() << endl;
			cout << "Space color is: " << spaceColor << endl;
			cout << "Orientation is: " << orientation << endl;
			
			//Simulation rules
			if (spaceColor == BLANK_SPACE)
			{
				switch (orientation)
				{
				case 'N':
					ant.setNewOrientation('E');
					changeSpCol(arr, xPos, yPos);
					ant.setNewXPosition(ant.moveEW(ant, 1, columns));
					break;
				case 'E':
					ant.setNewOrientation('S');
					changeSpCol(arr, xPos, yPos);
					ant.setNewYPosition(ant.moveNS(ant, 1, rows));
					break;
				case 'S':
					ant.setNewOrientation('W');
					changeSpCol(arr, xPos, yPos);
					ant.setNewXPosition(ant.moveEW(ant, -1, columns));
					break;
				case 'W':
					ant.setNewOrientation('N');
					changeSpCol(arr, xPos, yPos);
					ant.setNewYPosition(ant.moveNS(ant, -1, rows));
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
					ant.setNewXPosition(ant.moveEW(ant, -1, columns));
					break;
				case 'E':
					ant.setNewOrientation('N');
					changeSpCol(arr, xPos, yPos);
					ant.setNewYPosition(ant.moveNS(ant, -1, rows));
					break;
				case 'S':
					ant.setNewOrientation('E');
					changeSpCol(arr, xPos, yPos);
					ant.setNewXPosition( ant.moveEW(ant, 1, columns));
					break;
				case 'W':
					ant.setNewOrientation('S');
					changeSpCol(arr, xPos, yPos);
					ant.setNewYPosition(ant.moveNS(ant, 1, rows));
					break;
				default:
					break;
				}
			}
			printBoard(arr, rows, columns, ant);
		}
		//Clean up dynamically allocated memory
		for (int i = 0; i < rows; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
	}

	menu(&userInput, "Press 1 to play again. Press 2 to end the simulation");
	if (userInput == 1)
	{
		main();
	}

	return 0;
}
/**********************************************************************
						randStart
This function askjs the user if they want to assign a random number 
for ant's position. If the user opts to do so, the randoms are generated 
and assigned to ant's initialX and initalY positions.
**********************************************************************/

bool randStart(string question, int& initX, int& initY, int rows, int columns)
{
	bool result = false;
	int	answer = 0;
	//Get ant's initial position
	do
	{
		//Ask the user to enter 1 or 2
		inputValidInt(question, answer);

	} while (answer !=1 && answer !=2);
	
	//Generate random x,y position that fit on the board
	if (answer == 1)
	{
		initX = rand() % (columns);
		initY = rand() % (rows);
		result = true;
	}

	return result;
}

/*******************************************************
					menu
This function takes a pointer to an integer and a string to give 
the user two choices. It validates the input for an integer. 
Once 1 or 2 is entered the funtion sets pointer's value and exits. 
*******************************************************/
void menu(int *userInput, string question)
{
	do
	{
		inputValidInt(question, *userInput);
	} while (*userInput != 1 && *userInput != 2);
}


/*********************************************************************
					changeSpCol
This function takes the pointer to pointer of arrays of chars and two integers
to determine the color and to reverse it
*********************************************************************/
void changeSpCol(char** arr, int row, int col)
{
	char spaceColor = arr[row][col];
	if (spaceColor == BLANK_SPACE)
	{
		arr[row][col] = '#';
	} 
	else if (spaceColor == '#')
	{
		arr[row][col] = BLANK_SPACE;
	}
}

/*********************************************************************
					inputValidInt
This function takes a string and a reference to an integer. It validates 
user input for an integer. Once an integer is entered, the function returns
true.
*********************************************************************/
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

/*********************************************************************
					printBoard
		This function prints the board
*********************************************************************/
void printBoard(char** array, int rows, int cols, Ant ant)
{
	//Referenced codereview.stackexchange.com/questions/51716/shortest-possible-way-of-printing-a-specific-board
	string border = "";
	border.assign(cols + 2, '_');
	cout << border << endl;

	for (int i = 0; i < cols; i++) {

		cout << "|";

		for (int j = 0; j < rows; j++) {

			if (j == ant.getXPosition() && i == ant.getYPosition())
			{
				cout << '*';
			}
			else
			{
				cout << array[j][i];
			}
		}

		cout << "|" << endl;
	}
	cout << border.assign(cols + 2, '_') << endl;
}