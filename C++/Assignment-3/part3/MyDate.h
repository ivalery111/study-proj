
#ifndef _MYDATE
#define _MYDATE

#include <iostream>
#include <iomanip>

using namespace std;

class MyDate {
private:
	int day, month, year;
	
public:
	MyDate() { day = 0; month = 0; year = 0; }
	MyDate(int, int , int ) throw (const char*);

	const MyDate& operator=(const MyDate& obj);
	friend ostream& operator<<(ostream& out, const MyDate& obj);
	bool operator==(const MyDate& obj);
	bool operator>(const MyDate& other) const;
};

#endif // !_MYDATE



