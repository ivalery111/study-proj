#include "Game.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// constructor/default constructor
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Game::Game(int number) {

	if (number == 1) {
		cout << "Number of card must be minimun 2! Goodbye!" << endl;
		exit(1);
	}
	else {	//create pile
		arr = new Pile(number);
		open_cards = 0;
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// destructor
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Game::~Game() {
	if (arr) {
		delete arr;
		arr = NULL;
	}
}



//////////////////////////////////////////////////////////////////////
// Methods (public interface)
//////////////////////////////////////////////////////////////////////
void Game::Run() {
	int row = 0, col = 0, index1 = 0, index2 = 0, end = this->arr->Get_size();
	bool contin = true, in_range=false;
	char* _temp1 = NULL;
	char* _temp2 = NULL ;

	while (contin != false) {

		cout << "Choose the first card by entering the row and col numbers: " << endl;
		cout << " row: "; cin >> row;
		cout << " col: "; cin >> col;
		index1 = Calc_index(row, col);//index of first card. Get -1 if not in range
		if (index1 == -1) {//if index1 not in range, then...
			cout << "Error! Incorrect row or column of first card!" << endl;
		}
		else {//index1 in range, then...
			arr->Set_card_state(index1, true);//open card in index 'index1'
			cout << *arr << endl;//print all cards one more time

			//second card
			cout << "Choose the second card by entering the row and col numbers: " << endl;
			cout << " row: "; cin >> row;
			cout << " col: "; cin >> col;
			index2 = Calc_index(row, col);//index of second card. Get -1 if not in range
			if (index2 == -1) {//if index2 not in range, then...
				cout << "Error! Incorrect row or column of second card!" << endl;
				arr->Set_card_state(index1, false);// 'close' first card
				cout << *arr << endl;
			}
			else {//if index2 in range, then...
				arr->Set_card_state(index2, true);//open second card
				cout << *arr << endl;

			//this block check if cards have a matching
			
			_temp1 = new char[2];//temporary data for first card
			strcpy(_temp1, arr->Get_card_sign(index1));
			_temp1[1] = '\0';

			_temp2 = new char[2]; //temporary data for second card
			strcpy(_temp2, arr->Get_card_sign(index2));
			_temp2[1] = '\0';

			//check if user opened all cards
			if (strcmp(_temp1, _temp2) == 0 && index1 != index2){
				open_cards++;

				if (Is_all_cars_open()) {
					cout << "The End!" << endl;
					contin = false;
				}//---

				else {//Match
					cout << "Match! Do you want to continue? 1 - Yes, 2 - No\nYour choose: ";
					int choose = 2; cin >> choose;
					if (choose == 2) {
						contin = false;
					}
					else {
						system("cls");
						cout << *arr << endl;
					}
				}//-----------
			}
			else {//No match
				cout << "No match! Do you want to continue? 1 - Yes, 2 - No\nYour choose: ";
				int choose = 2; cin >> choose;
				arr->Set_card_state(index1, false);
				arr->Set_card_state(index2, false);
				if (choose == 2) {
					contin = false;
				}
				system("cls");
				cout << *arr << endl;
			}//--------------
			}
			
		}
	}

}


//////////////////////////////////////////////////////////////////////
// Methods (private interface)
//////////////////////////////////////////////////////////////////////

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Calc_index
//
// Calculate index of Card in array
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int Game::Calc_index(int row, int col) {
	int index = (col - 1) + ((row - 1) * 5);

	if(index>=0 && index<arr->Get_size()){
		return index;
	}
	else {
		return -1;
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Is_all_cars_open
//
// Check if all cards were opened
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool Game::Is_all_cars_open() {
	bool res = false;
	for (int i = 0; i < arr->Get_size(); i++) {
		if (arr->Get_card_state(i)) {
			res = true;
		}
		else {
			//res = false;
			return false;
		}
	}
	return res;
}
