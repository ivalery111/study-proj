#include "Worker.h"

Worker::Worker(char* _name, char _id[], int _year, int _month, int _day, int _tariff) :birht(_year, _month, _day), tariff(_tariff), work_hours(0), ex_hours(0) {

	name = new char[strlen(_name) + 1]; strcpy(name, _name);
	strcpy(id, _id);
}

Worker::Worker(const Worker& obj) {

	this->name = new char[strlen(obj.name) + 1]; strcpy(name, obj.name);

	strcpy(this->id, obj.id);
	this->birht = obj.birht;
	this->tariff = obj.tariff;
	this->work_hours = obj.work_hours;
	this->ex_hours = obj.ex_hours;
}

void Worker::Print() const {
	cout << "Information of worker:" << endl;
	cout<<"\tName: "<<this->name << endl;
	cout << "\tID: " << this->id << "\n" <<
		"\tBirhtdate: "; this->birht.Print();
	cout << "\tTariff: " << this->tariff << endl;
	cout << "\tWork Hours: " << work_hours <<"\n"<<
		"\tExtra Hours:" << ex_hours << endl;
	cout << "\tWage = " << Get_Wage() << endl;
}

void Worker::Set_work_hours() {
	int _work_hours = 0, _ex_hours = 0;
	cout << "Enter new work hours: "; cin >> _work_hours;
	cout << "Enter new extra-hours: "; cin >> _ex_hours;

	this->work_hours = _work_hours;
	this->ex_hours = _ex_hours;
}
