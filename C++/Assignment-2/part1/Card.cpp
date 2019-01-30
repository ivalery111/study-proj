#include "Card.h"
#define _CRT_SECURE_NO_WARNINGS
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// constructor/default constructor
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Card::Card(char* str, bool _state){// : sign(str),state(_state) { 
	if (str) {
		sign = new char[2];
		strcpy(sign, str);
		sign[1] = '\0';
		state = _state;
	}
	else {
		sign = NULL;
		state = false;
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// copy constructor = parametr by Value
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Card::Card(const Card& obj) {
	state = obj.state;

	if (obj.sign) {//if obj not empty
		sign = new char[2];
		strcpy(sign, obj.sign);
		sign[1] = '\0';
	}
	else {
		sign = NULL;
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// destructor
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Card::~Card() {
	if (sign) {
		delete[] sign;
		sign = NULL;

	}
}

///////////////////// operators ///////////////////// 

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// operator =
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Card& Card::operator=(const Card& obj) {

	//checking self-assignments
	if (this != &obj) {
		
		if (sign) {
			delete sign;
			sign = NULL;
		}
		//copy obj to current Card
		state = obj.state;
		if (obj.sign) {
			//sign = new char(*obj.sign);// sign will get obj.sign
			sign = new char[2];
			strcpy(sign, obj.sign);
			sign[1] = '\0';
		}
	}
	return *this;
}

///////////////////// logical operators ///////////////////// 

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// operator !
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Card::operator!() {
	state = !state;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// operator ==
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool Card::operator==(const Card& right) {

	if ((sign) && (right.sign)) {
		return strcmp(sign, right.sign);// if equals, return 1
	}
	else{
		return ((sign == NULL) && (right.sign == NULL));
	}
}


//////////////////////////////////////////////////////////////////////
// Friend Functions 
//////////////////////////////////////////////////////////////////////

///////////////////// I/O operators ///////////////////// 

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// operator <<
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ostream& operator<<(ostream& out, const Card& obj) {

	//verify that card is not empty to avoid access violation
	if (obj.sign) {
		
		if (obj.state) {//state = true, card open
			out << "[" << *obj.sign << "]";
		}
		else {
			out << "[?]";
		}
	}
	return out;
}

//////////////////////////////////////////////////////////////////////
// Methods (public interface)
//////////////////////////////////////////////////////////////////////


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Set_card_sign - change the sign
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Card::Set_card_sign(char* _sign) {

	if (sign == NULL) {
		sign = new char[2];
		strcpy(sign, _sign);
		sign[1] = '\0';
	}
	else {
		strcpy(sign, _sign);
	}

}
