#include "millionaire.h"
#include <string>
#include <iostream>
using namespace std;

millionaire::millionaire()
{
}

void millionaire::play(void)
{
	welcome();

	return;
}

void millionaire::welcome(void)
{
	std::string response;

	cout << "Welcome to Who Wants to be a Millionaire?" << endl;
	cout << "Are you ready to play? (Type yes or no)" << endl;
	
	while(1)
	{
		getline(std::cin, response, '\n' );
		if (response == "yes")
			{
				cout << "Let's begin!" << endl;
				return;
			}
		else if (response == "no")
			{
				cout << "Maybe next time!" << endl;
				cin.get();
				exit(1);
			}
		else cout << "You must type yes or no" << endl;
	}
}