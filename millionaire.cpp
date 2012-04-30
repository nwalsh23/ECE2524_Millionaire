#include "millionaire.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

millionaire::millionaire()
{
	round = 1;
	score = 0;
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
					if (check_answer(answer, response)) adjust_score();
					if (round == 16) exit(0);
					else
						{
							cout << "Press Enter to proceed to the next question" << endl;
							cin.get();
						}
					
				}
			questions.close();
		}

	return;
}

bool millionaire::check_answer(string answer, string response)
{
	if (answer == response)
		{
			cout << "You got it right!" << endl;

			return true;
		}	
	else
		{
			cout << "You got it wrong!" << endl;

			return false;
		}
}

void millionaire::adjust_score(void)
{
	switch (round)
		{
			case 1:
				score = 100;
				break;
			case 2:
				score = 200;
				break;
			case 3:
				score = 300;
				break;
			case 4:
				score = 500;
				break;
			case 5:
				score = 1000;
				break;
			case 6:
				score = 2000;
				break;
			case 7:
				score = 4000;
				break;
			case 8:
				score = 8000;
				break;
			case 9:
				score = 16000;
				break;
			case 10:
				score = 32000;
				break;
			case 11:
				score = 64000;
				break;
			case 12:
				score = 125000;
				break;
			case 13:
				score = 250000;
				break;
			case 14:
				score = 500000;
				break;
			case 15:
				score = 1000000;
				break;
			default:
				
				break;
		}

	round++;
	cout << "You total sum is $" << score << endl;
	return;
}