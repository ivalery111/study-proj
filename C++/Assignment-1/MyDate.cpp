#include "MyDate.h"

MyDate::MyDate() {
	year = 2000;
	month = 1;
	day = 1;
}
MyDate::MyDate(int _y, int _m, int _d) : year(_y), month(_m), day(_d) {

	if (!(Check_Date(year, month, day))) {
		year = 2000;
		month = 1;
		day = 1;

		_min = new MyDate(year, month, day);
	}
}
bool MyDate::is_before(MyDate& obj) {

	if ((year < obj.year) || (month < obj.month) || (day < obj.day)) {
		_min = this;
		_max = (&obj);
		return true;
	}
	else { 
		
		return false; 
	}
}
bool MyDate::Check_Date(int _year, int _month, int _day) {

	if ((_day < 1 || _day >31) || (_month < 1 || _month >12) || (_year <2000) ) return false;
	else { return true; }
}

bool MyDate::operator==(const MyDate & obj)
{
	if (this->year == obj.year &&
		this->month == obj.month &&
		this->day == obj.day)
		return true;
	//else
	return false;
}
