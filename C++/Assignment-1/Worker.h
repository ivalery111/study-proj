#pragma once
#ifndef _WORKER
#define _WORKER

#include <iostream>
#include "MyDate.h"

using namespace std;

class Student; //predeclaration

class Worker {
private:
	char* name;
	char id[10];
	MyDate birht;
	float tariff = 0;
	int work_hours = 0;
	int ex_hours = 0;
public:

	Worker(char* _name, char _id[], int _year, int _month, int _day, int _tariff);
	Worker(const Worker& obj);
	~Worker() { delete[]name; }

	//gets
	float Get_Wage() const;
	MyDate& Get_Birth() { return birht; }
	char* Get_Name() const { return name; }

	//sets
	void Set_work_hours();

	//friends
	friend bool check( Student** stud, int size_stud, Worker** work, int size_work, char* _id);
	friend int birthday(Student** stud, int size_stud, Worker** work, int size_work, MyDate& obj);

	//others
	void Print() const;
	

};

//inlines functions
inline float Worker::Get_Wage() const {

	return (work_hours*tariff) + (ex_hours*tariff*1.5);
}

#endif // !_WORKER
