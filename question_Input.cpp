//////////////////////////////////////////////////////// 
// ECE 2524, Who wants to be a millionaire?, Bryse Flowers
// 
// File name:   questionInput.cpp
// Description: Reads questions from a text file
// Date:        4/2012  
// 


#include "questionInput.h"

//Default constructor
question_input::question_input(void)
{
	//Clear the questions list
	questions.erase();
	
}

//Constructor with file input
question_input::question_input(string filename)
{
	questions.erase();

	try
	{
		//Declare a new stream handle
		ifstream inFile;

		//Attempt to open the file
		inFile.open(filename);
		if(inFile.fail()) throw "Input file could not be opened.";

		//Declare a character array to store the line
		char line[4096];

		//temporary storage to pass into addQuestion
		std::string question;
		std::string correctAnswer;
		std::string tempStorage;
		std::string[3] otherAnswers;

		while(!inFile.eof())
		{
			//Clear the character array
			for(int i=0;i<256;i++)
				line[i] = NULL;

			//Get the question
			inFile.getline(line,4096);

			//Store the question
			question = line;
			
			//Clear the character array
			for(int i=0;i<256;i++)
				line[i] = NULL;

			//Get the correct answer
			inFile.getline(line,4096);

			//Store the correct answer
			correctAnswer = line;

			//Clear the character array
			for(int i=0;i<256;i++)
				line[i] = NULL;
			
			//Get the incorrect answers
			inFile.getline(line,4096);
			tempStorage = line;
			otherAnswers[0] = tempStorage;

			//Clear the character array
			for(int i=0;i<256;i++)
				line[i] = NULL;
			
			inFile.getline(line,4096);
			tempStorage = line;
			otherAnswers[1] = tempStorage;

			//Clear the character array
			for(int i=0;i<256;i++)
				line[i] = NULL;
			
			inFile.getline(line,4096);
			tempStorage = line;
			otherAnswers[2] = tempStorage;

			//Add the question to the list
			addQuestion(question, correctAnswer, otherAnswers);

			//Get the garbage line and throw it away
			inFile.getline(line,4096);

			//Clear the character array
			for(int i=0;i<256;i++)
				line[i] = NULL;
		}
	}
	catch(char * str)//Catch the error and output it
	{
		cerr << "Exception raised in questionInput.\nException was: " << str << endl;
		cin.ignore();
		return EXIT_FAILURE;
	}
}

//Destructor
question_input::~question_input()
{
	questions.erase();
	cout << "questionInput destroyed." << endl;
}

//Add a question to the list
question_input::addQuestion(string question, string correctAnswer, string[3] otherAnswers)
{
	//Declare a tempNode
	questionNode temp;

	//Store the values
	temp.question = question;
	temp.correctAnswer = correctAnswer;
	temp.otherAnswers = otherAnswers;

	//Add it to the list
	list.push_back(temp);
}

//Operator to output questions to console
ostream &operator<<(ostream &output)
{
	list<questionNode>::iterator i;

	output << "Begin questions\n";
	
	for(i=questions.begin(); i != questions.end(); ++i)
	{
		output << *i.question << endl << *i.correctAnswer << endl
			 << *i.otherAnswers[0] << endl << *i.otherAnswers[1]
			 << endl << *i.otherAnswers[2] << endl
			 << "-------------------------------------------" << endl;
	}

	output << "End questions\n";

	return output;
}
