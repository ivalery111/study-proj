#ifndef _GAME
#define _GAME

#include "Pile.h"

class Game {
private:
	//-- data members --//
	Pile* arr;
	int open_cards;
	int Calc_index(int row, int col);

	bool Is_all_cars_open();

public:
	//-- constructors/destructor --//
	explicit Game(int number = 0);//ctor
	~Game();

	//methods
	void Run();
};

#endif // !_GAME


