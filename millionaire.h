#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class millionaire
{
	public:
		int tier;
		int round;
		int score;
		int life1;
		int life2;
		bool lifeline;
	
		millionaire();

		void play(void);
		void welcome(void);
		void question_read(void);
		bool check_answer(string answer, string response);
		void adjust_score(void);
		void final_screen(void);
		void life_line(string A, string B, string C, string D, string answer);
	
};