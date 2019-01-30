#ifndef _CARD
#define _CARD

#include <iostream>
using namespace std;

class Card {
private:
	//-- data members --//
	char* sign; 
	bool state;

public:
	//-- constructors/destructor --//
	Card(char* str = NULL , bool _state=false);
	Card(const Card& obj);
	~Card();

	//-- operators --//
	Card& operator=(const Card&);


	//-- logical operators --//
	void operator!();
	bool operator == (const Card& right);

	//I/O operator
	friend ostream& operator<<(ostream& out, const Card& obj);

	//-- methods --//
		//sets
	void Set_card_sign(char* _sign);
	void Set_card_state(bool _state);
		//gets
	char* Get_card_sign() const;
	bool Get_card_state() const;


};
#endif // !_CARD

///////////////////// inline functions /////////////////////

inline void Card::Set_card_state(bool _state) {
	state = _state;
}

inline char* Card::Get_card_sign() const {
	return sign;
}

inline bool Card::Get_card_state() const {
	return state;
}


