#pragma once
#ifndef _STUDENT
#define _STUDENT

#include <iostream>
#include "MyDate.h"

using namespace std;

class Worker;//prediclaration for funcs check,birthday

class Student {
private:
	char* name;
	char id[10];//9+1-for '\0'
	MyDate birht;
	int kurs = 0;
	int* arr_kurs=NULL;
public:

	Student();
	Student(char* _name, char _id[], int _year, int _month, int _day);
	Student(char* _name, char _id[], int _year, int _month, int _day,int _kurs);
	Student(const Student& obj);
	~Student() {delete[] arr_kurs;delete[]name;}

	//gets
	float Get_avr_grade() const;
	char* Get_Name() const { return name; }
	MyDate& Get_Birth() { return birht; }
	int Get_mark(int index) const { return arr_kurs[index]; }

	//sets
	void Add_student(Student* source, int size, Student& obj);
	void Insert_grades();
	bool Add_grade(int _grade);

	//friends
	friend bool check(Student** stud, int size_stud, Worker** work, int size_work, char* _id);
	friend int birthday(Student** stud, int size_stud, Worker** work, int size_work, MyDate& obj);

	//overloads
	bool  operator==(Student obj);

	//others
	void Print() const;
};

#endif // !_STUDENT

