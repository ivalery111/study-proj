
#include <iostream>
#include <stdlib.h>
#include <fstream>

#include "MyDate.h"
#include "MyArr.h"

#define STR_LEN 15

using namespace std;


int How_strings_file(char* _path) {
	char* str = new char[STR_LEN];
	int count = 0;
	ifstream base(_path);//open file
	while (!base.eof())
	{
		base.getline(str, STR_LEN, '\n');
		count++;
	}
	base.close();
	delete str;
	//cout << count<< '\n';

	return count;
}

// Write from file( _path - address) to array( T - is type of array)
template <class T>
T* File_To_Array(char* _path, int& _rsize) {

	T* arr = NULL;

	char buff[STR_LEN];
	ifstream fin(_path); //open file for reading

	if (!fin.is_open()) {
		cout << "Cannot open file!" << endl;
	}
	else {
		int size = How_strings_file(_path);
		_rsize = size;
		float value = 0;
		arr = new T[size];
		for (int i = 0; i < size; i++) {
			//fin >> buff;
			fin.getline(buff, STR_LEN);
			//cout << "Writing " << buff << " in array..." << endl;
			value = atof(buff);// buff;//?
			arr[i] = value;
		}
	}
	return arr;

}

template <class T>
//bool Date_To_Ints(int& _day, int& _month, int& _year, char* _path) {
bool Date_To_Ints(T& _arr, char* _path) {

	char temp[4];
	char buff[STR_LEN];
	int str_size = 0;
	int _day = 0, _month = 0, _year = 0;
	int size = How_strings_file(_path);


	ifstream fin(_path); //open file for reading

	if (!fin.is_open()) {
		cout << "Cannot open file!" << endl;
	}
	else {

		for (int i = 0; i < size; i++) {
			fin.getline(buff, STR_LEN);//get the string
			str_size = strlen(buff);
			buff[str_size] = ' ';
			buff[str_size + 1] = '\0';
			int index = 0;
			int in_index = 0;
			int choice = 0;
			while (buff[index] != '\0') {

				if (buff[index] != ' ') {
					temp[in_index] = buff[index];
					in_index++;
				}
				else {
					if (choice == 0) {
						_day = atoi(temp);
						temp[0] = ' ';
						temp[1] = ' ';
						temp[2] = ' ';
						temp[3] = ' ';
						in_index = 0;
						choice = 1;
					}
					else {
						if (choice == 1) {
							_month = atoi(temp);
							temp[0] = ' ';
							temp[1] = ' ';
							temp[2] = ' ';
							temp[3] = ' ';
							in_index = 0;
							choice = 2;
						}
						else {
							if (choice == 2) {
								_year = atoi(temp);
								temp[0] = ' ';
								temp[1] = ' ';
								temp[2] = ' ';
								temp[3] = ' ';

							}
						}

					}
				}
				index++;
			}

			MyDate m(_day, _month, _year);
			//Add object MyDate
			_arr += m;

		}
	}
	return true;
}

int main() {

	float num = 0;
	char* _path1, *_path2;
	int size1, size2;
	//--------------------------------------------------------------------
	_path1 = "arrfloat1.txt";
	_path2 = "arrfloat2.txt";

	float* farr1, *farr2;

	farr1 = File_To_Array<float>(_path1, size1);
	farr2 = File_To_Array<float>(_path2, size2);


	MyArr<float>* mfarr = new MyArr<float>(farr1, size1);
	MyArr<float>* mfarr2 = new MyArr<float>(farr2, size2);


	//--------------------------------------------------------------------
	_path1 = "arrdate1.txt";
	_path2 = "arrdate2.txt";

	MyArr<MyDate> m1;
	MyArr<MyDate> m2;
	try
	{
		Date_To_Ints(m1, _path1);
		Date_To_Ints(m2, _path2);
	}
	catch (const char* mess)
	{
		cout << mess << endl;
	}
	//--------------------------------------------------------------------
	int dday = 0, mmonth = 0, yyear = 0;
	float numb = 0;
	MyDate* mtemp = NULL;


	cout << "First float object:" << endl;
	cout << "\tEnter first float number: "; cin >> numb;
	*mfarr += numb;
	cout << "\tMax number is " << (*mfarr->FindMax()) << " and Min number is " << (*mfarr->FindMin()) << endl;
	if (mfarr->Is_Sorted())
		cout << "\tArray is sorted!" << endl;
	else
		cout << "\tArray not sorted!" << endl;
	cout << "--------------------------------------------" << endl;


	cout << "Second float object:" << endl;
	cout << "\tEnter second float number: "; cin >> numb;
	*mfarr += numb;
	cout << "\tMax number is " << (*mfarr->FindMax()) << " and Min number is " << (*mfarr->FindMin()) << endl;
	if (mfarr->Is_Sorted())
		cout << "\tArray is sorted!" << endl;
	else
		cout << "\tArray not sorted!" << endl;
	cout << "--------------------------------------------" << endl;


	cout << "First MyDate object:" << endl;
	cout << "\tEnter first date: " << endl;
	cout << "\t     Day: "; cin >> dday;
	cout << "\t     Month: "; cin >> mmonth;
	cout << "\t     Year: "; cin >> yyear;

	try
	{
		mtemp = new MyDate(dday, mmonth, yyear);
		m1 += (*mtemp);
	}
	catch (const char* e)
	{
		cout << e << endl;
	}

	return 0;
}