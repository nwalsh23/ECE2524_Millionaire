#include "millionaire.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

millionaire::millionaire()
{
	score = 5;
	chances = 1;
	win = false;
}

void millionaire::play(void)
{
	welcome();
	question_read();
	cout << "DONE" << endl;
	while(1);
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
				cout << "Let's begin!" << endl << endl;
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

void millionaire::question_read(void)
{
	std::string response;
	ifstream questions ("Flowers_Questions");
	string question, A, B, C, D, answer;


	if (questions.is_open())
		{
			while ( questions.good() )
				{
					
					getline (questions, question);
					cout << question << endl;
					getline (questions, A);
					cout << A << endl;
					getline (questions, B);
					cout << B << endl;
					getline (questions, C);
					cout << C << endl;
					getline (questions, D);
					cout << D << endl;
					

					cout << endl;
					cout << "Enter an answer or type Options to get some help" << endl;
					getline(std::cin, response, '\n' );
					getline (questions, answer);
					check_answer(answer, response);
					
				}
			questions.close();
		}

	return;
}

void millionaire::check_answer(string answer, string response)
{
	if (answer == response)
		{
			cout << "You got it right!" << endl;
			score = score*2;
			cout << "You total sum is $" << score << endl;
			cout << "Press Enter to proceed to the next question" << endl;
			cin.get();
		}	
	else
		{
			cout << "You got it wrong!" << endl;
			cout << "Press Enter to proceed to the next question" << endl;
			cin.get();
		}

	return;
}