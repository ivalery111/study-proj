
#include "Game.h"


int main() {

	int num = 0;
	cout << "Enter number of cards you want to play with" << endl;
	cin >> num;
	Game m(num);
	m.Run();


	return 0;
}