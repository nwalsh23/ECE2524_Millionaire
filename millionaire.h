#include <iostream>

using namespace std;

class millionaire
{
	public:
		int score;
		int chances;
		bool win;
	
	private:
		play(void);
		welcome(void);
		question_read(void);
		check_answer(char answer);
		adjust_score(void);
		check_chances(void);
		final_screen(void);
	
};