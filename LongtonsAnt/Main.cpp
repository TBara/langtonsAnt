#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

bool inputValidInt(std::string, int&);

int main()
{
	int initialX = 0;
	int initialY = 0;
	int userInput = 0;

	inputValidInt("Press 1 to start Langton Ant simulation or press 2 to exit the program", userInput);

	if (userInput == 1)
	{
		cout << "You chose: " << userInput << endl;


	}


	cin.ignore();
	cin.get();
	return 0;
}

bool inputValidInt(std::string question, int& userInp)
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
		}
		if (floor(integer) == ceil(integer))
		{
			validInt = true;
			userInp = integer;
		}
	} while (!validInt);
	return validInt;
}
