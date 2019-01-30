#pragma once
#ifndef _MYDATE
#define _MYDATE

#include <iostream>

using namespace std;

class MyDate {
private:
	int year;
	int month;
	int day;

	static MyDate* _min;
	static MyDate* _max;

public:
	MyDate(); //ctor without parametrs
	MyDate(int _y, int _m, int _d);

	

	//gets
	int const Get_Year() { return year; }
	int const Get_Month() { return month; }
	int const Get_Day() { return day; }

	//overloads
	bool operator==(const MyDate& obj);//work!

	//others
	bool is_before(MyDate& obj);
	bool Check_Date(int _year, int _month, int _day);

	//inlines
	inline static void MyDate::ShowMinMax() {
		cout << "Max: "; MyDate::_max;
		cout << "\nMin: "; MyDate::_min;
	}
	inline void MyDate::Print() const {
		cout << day << "/" << month << "/" << year << endl;
	}

};

#endif // !_MYDATE
