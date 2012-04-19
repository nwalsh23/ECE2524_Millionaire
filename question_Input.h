//////////////////////////////////////////////////////// 
// ECE 2524, Who wants to be a millionaire?, Bryse Flowers
// 
// File name:   questionInput.h
// Description: Header file for questionInput
// Date:        4/2012  
// 


#ifndef _QUESTIONINPUT_H_
#define _QUESTIONINPUT_H_

#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <functional>
#include <deque>
#include <list>

using namespace std;

// Node holds the question and the answers to the question
struct questionNode
{
	string question; //Holds the question data
	string correctAnswer; // Holds the correct answer to the questionNode
	string[3] otherAnswers;
	
};

class question_input
{

	//Outputs the questions to the console
	friend ostream &operator<<(ostream &output);
	
public:

	//Default Constructor
	question_input(void);

	//Constructor which accepts the file name of the location where the questions are stored
	question_input(string filename);

	//Adds a question to the linked list
	void addQuestion(string questionInput, string correctAnswer, string[3] otherAnswers);
	
protected:

private:
	list<questionNode> questions;
};

#endif // _QUESTIONINPUT_H_

