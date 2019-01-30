#ifndef _PILE
#define _PILE
#include "Card.h"
class Pile {
private:
	//-- data members --//
	int size;
	Card* pile_arr;

	void Fill_Pile();
	bool Swap_index(int, int);
	bool Mix_indexes();
	void Stop_for_30_sec()const;
	
public:
	//-- constructors/destructor --//
	explicit Pile(int _size); //explicit because we have one ctor and we want to run just him
	Pile(const Pile& obj);
	~Pile();

	//-- operators --//
	Pile& operator=(const Pile& right);

	//indexing operator
	Card& operator[](int) const;

	//I/O operator
	friend ostream& operator<<(ostream& out, const Pile& obj);

	//-- methods --//
		//sets
	void Set_card_sign(int index, char* _sign);
	void Set_card_state(int index, bool _state);
	void Set_all_card_state(bool _state);
		//gets
	int Get_size() const { return size; }
	char* Get_card_sign(int index) const;
	bool Get_card_state(int index) const;

};

#endif // !_PILE

