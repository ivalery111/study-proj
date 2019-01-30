
#include "MyDate.h"
using namespace std;

//--------------------------
// CTOR / DTOR
//--------------------------


MyDate::MyDate(int _day, int _month, int _year) throw(const char*): 
	day(_day),month(_month),year(_year)
{

	if (_month < 1 || _month >12) {
		throw "Invalid month! Valid range ->  1 - 12";
	}
	if (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12) {
		if (_day < 1 || _day > 31) {
			throw "Invalid day! Valid range -> 1  -  31";
		}
	}
	if (_month == 4 || _month == 6 || _month == 9 || _month == 11) {
		if (_day < 1 || _day > 30) {
			throw "Invalid day! Valid range -> 1  -  30";
		}
	}
	if (_month == 2 ) {
		//leap year
		if (((_year % 4 == 0) && (_year % 100 != 0)) || (_year % 400 == 0)) {
			if (_day < 1 || _day > 29) {
				throw "Invalid day! Valid range -> 1  -  29";

			}
		}
		else {
			if (_day < 1 || _day > 28) {
				throw "Invalid day! Valid range -> 1  -  28";
			}
		}
	}
	if (_year < 1900 || year > 20171) {
		throw "Invalid year";
	}

}


//--------------------------
// OVERLOADINGS
//--------------------------

const MyDate& MyDate::operator=(const MyDate& obj) 
{
	if (this != &obj) {
		day = obj.day;
		month = obj.month;
		year = obj.year;
		}
	return *this;
}

bool MyDate::operator==(const MyDate & obj)
{
	if (day == obj.day &&
		month == obj.month&&
		year == obj.year) {
		return true;
	}
	return false;
}

//if *this early -> return true
bool MyDate::operator>(const MyDate& other) const {
	
	if (this->year < other.year) return true;
	if (this->month < other.month) return false;
	if (this->day < other.day) return true;

}

ostream & operator<<(ostream & out, const MyDate & obj)
{
	out << "Day = " << obj.day << " , Month = " << obj.month << " , Year = " << obj.year << endl;
	return out;
}
