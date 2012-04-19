//////////////////////////////////////////////////////// 
// ECE 2524, Monopoly, Bryse Flowers
// 
// File name:   question_Input.cpp
// Description: Reads questions from a text file
// Date:        4/2012  
// 

#include "simulate.h"


int main(int argc, char *argv[])
{
	try
	{
		//Validate that a proper number of command line arguments were given
		if(argc<3)throw "Not enough arguments provided on command line.  <input file> <output file> is needed.";
		if(argc>3)throw "To many arguments provided on command line. Only <input file> <output file> is needed.";

		//Read the file names into the program
		string inFileName = argv[1];
		string outFileName = argv[2];

		//Declare new stream handle
		ifstream inFile;

		//Attempt to open the file
		inFile.open(inFileName);
		if(inFile.fail())throw "Input file could not be opened.";

		inFile.close();


		cin.ignore();
		return EXIT_SUCCESS;
	}
	catch(char * str)//Catch the error and output it
	{
		cerr << "Exception raised in client code.\nException was: " << str << endl;
		cin.ignore();
		return EXIT_FAILURE;
	}
}//End Client Code
