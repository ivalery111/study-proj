#include "Pile.h"
#include <time.h>
#include <ctime>
#include <stdlib.h>

#define PILE_MAX 52
#define PILE_MIN 20
#define _rand(min, max) ( rand() % ((max) - (min) + 1) + (min) )

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// constructor/default constructor
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Pile::Pile(int _size) : size(_size) {
	if (_size % 2 != 0) size--;

	if (size > PILE_MAX) { //if size>52 then create arr with 20 cards
		size = PILE_MIN;
		pile_arr = new Card[size];
	}
	else {
		pile_arr = new Card[size];
	}
	Fill_Pile();
	if (Mix_indexes() == false) {
		cout << "Error! Fun.Pile::Pile()" << endl;
	}



}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// copy constructor
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Pile::Pile(const Pile& obj) {
	if (obj.pile_arr) {
		size = obj.size;
		delete[] pile_arr;// 'clean' pile_arr
		pile_arr = new Card[size];//allocate memory for new pile
		for (int i = 0; i < size; i++) {
			pile_arr[i] = obj.pile_arr[i];
		}
	}
	else {
		pile_arr = NULL;
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// destructor
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Pile::~Pile() {
	if (pile_arr) {
		delete[] pile_arr;
		pile_arr = NULL;
	}
}


///////////////////// operators ///////////////////// 

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// operator =
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Pile& Pile::operator=(const Pile& right) {

	//checking self-assignments
	if (this != &right) {

		//check if there's memory to release
		if (pile_arr) {
			delete[] pile_arr;
			pile_arr = NULL;
		}
		//copy right Pile to current Pile
		if (right.pile_arr) {
			size = right.size;
			pile_arr = new Card[size];
			for (int i = 0; i < size; i++) {
				pile_arr[i].Set_card_sign((right.pile_arr[i].Get_card_sign()));
				pile_arr[i].Set_card_state(right.pile_arr[i].Get_card_state());
			}
		}
	}
	return *this;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// operator []
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Card& Pile::operator[](int index)const{
	//if index if range
	if (index >= 0 && index < size) {
		return pile_arr[index];
	}
	else {
		cout << "Error->Pile::operator[]: Incorrect index" << endl;
		exit(1);
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// operator <<
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ostream& operator<<(ostream& out, const Pile& obj) {
	out << "     ";
	for (int i = 0; i < 5; i++)
		out << i + 1 << "   ";
	//check if pile dont empty
	if (obj.pile_arr) {
		int count = 1;
		for (int i = 0; i < obj.size; i++) {
			if (i % 5 == 0) {
				out << "\n"<<count<<"   ";
				count++;
			}
			out << obj.pile_arr[i] << " ";	
		}
	}
	out << "\n";
	return out;
}


//////////////////////////////////////////////////////////////////////
// Methods (public interface)
//////////////////////////////////////////////////////////////////////

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Set_card_sign(int,char*)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Pile::Set_card_sign(int index, char * _sign)
{
	if (_sign) {
		pile_arr[index].Set_card_sign(_sign);
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Set_card_state(int,bool)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Pile::Set_card_state(int index, bool _state) {
	pile_arr[index].Set_card_state(_state);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Get_card_sign(int)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
char* Pile::Get_card_sign(int index) const {
	return pile_arr[index].Get_card_sign();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Get_card_state(int)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool Pile::Get_card_state(int index) const {
	return pile_arr[index].Get_card_state();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Stop_for_30_sec
//
// Freeze console window for 30 second
// in order to allow to user to remember cards
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Pile::Stop_for_30_sec() const
{
	int sec = 1;
	clock_t start_time = clock();
	clock_t end_time = sec * 30000 + start_time;
	while (clock() != end_time) {
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Fill_Pile
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Pile::Fill_Pile() {
	srand(time(NULL));
	
	char* temp=new char[2];
	temp[1] = '\0';
	for (int i = 0; i < size; i=i+2) {
		temp[0] = ('A' + rand() % 26);
		pile_arr[i].Set_card_sign(temp);
		pile_arr[i + 1].Set_card_sign(temp);
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Swap_index
// 
// Changes index beetwen old and new index
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool Pile::Swap_index(int orig, int _new) {

	if ((orig >= 0 && orig < size) && (_new >= 0 && _new < size)) {
		Card* temp = new Card();
		*temp = pile_arr[_new];
		pile_arr[_new] = pile_arr[orig];
		pile_arr[orig] = *temp;
		return true;
	}
	else {
		cout << "Incorrect new or old index!" << endl;
		return false;
	}


}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Mix_indexes
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool Pile::Mix_indexes() {
	bool res = false;

	for (int i = 0; i < size; i++) {
		int num = _rand(0, size - 1);//num get random number 

		if (Swap_index(i, num)) {
			res = true;
		}
		else { res = false; }
	}

	cout << "Get ready, you have 30 seconds to memorize: " << endl;
	Set_all_card_state(true);//change all card's state to true in order to show to user
	cout << *this << endl;
	Stop_for_30_sec();//freeze to 30 seconds in order to let to user to memorize cards
	system("cls");//clean a window
	Set_all_card_state(false);//change to false in ordet to hide cards
	cout << *this << endl;
	
	return res;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Set_all_card_state
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Pile::Set_all_card_state(bool _state) {
	for (int i = 0; i < size; i++) {
		pile_arr[i].Set_card_state(_state);
	}
}

