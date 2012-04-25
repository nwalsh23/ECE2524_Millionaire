#include <iostream>

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
		char check_answer(char answer);
		void adjust_score(void);
		void check_chances(void);
		void final_screen(void);
	
};