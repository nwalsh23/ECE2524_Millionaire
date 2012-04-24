#include <iostream>

using namespace std;

class millionaire
{
	public:
		int score;
		bool win;
	
	private:
		play(void);
		welcome(void);
		question_read(void);
		check_answer(char answer);
		adjust_score(void);
	
};