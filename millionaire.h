#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class millionaire
{
	public:
		int score;
		int chances;
		bool win;
	
		millionaire();

		void play(void);
		void welcome(void);
		void question_read(void);
		void check_answer(string answer, string response);
		void adjust_score(void);
		void check_chances(void);
		void final_screen(void);
	
};