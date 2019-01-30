#include "Student.h"
using namespace std;

Student::Student() {
	name = "";
	strcpy(id, "000000000");
}
Student::Student(char* _name, char _id[], int _year, int _month, int _day) : birht(_year,_month,_day),kurs(0) {

	name = new char[strlen(_name) + 1]; strcpy(name, _name); // creating of student's name(ptr) and copy name from parametr to name(ptr)
	strcpy(id, _id);
	arr_kurs = NULL;
}
Student::Student(char* _name, char _id[], int _year, int _month, int _day, int _kurs) : birht(_year, _month, _day),kurs(_kurs) {
	name = new char[strlen(_name) + 1]; strcpy(name, _name); // creating of student's name(ptr) and copy name from parametr to name(ptr)
	strcpy(id, _id);
	Insert_grades();
}
Student::Student(const Student& obj) {
	this->name = new char[strlen(obj.name) + 1]; strcpy(name, obj.name);

	strcpy(this->id, obj.id);
	this->birht = obj.birht;
	this->kurs = obj.kurs;
	this->arr_kurs = obj.arr_kurs;
}
float Student::Get_avr_grade() const {

	float avr = 0;

	if (kurs != 0) {

		for (int i = 0; i < kurs; i++) {
			avr = avr + Get_mark(i);
		}
		return (avr / kurs);
	}
	else {
		return 0;
	}
}
//if grade between 0 - 100 then fun. add grade and return true
//else, return false
bool Student::Add_grade(int _grade) {

	if (_grade < 0 || _grade >100) return false;

	int* temp = new int[kurs+1];

	//copy all elements from old array to new array
	for (int i = 0; i < kurs; i++) {
		temp[i] = Get_mark(i); 
	}
	//add new grade to the end of new array
	temp[kurs] = _grade;
	
	//array of class get new addres of array with new grade
	arr_kurs = temp;
	//add grade = add course
	kurs++;

	return true;
}
void Student::Add_student(Student * source, int size,Student& obj)
{

	Student* temp = NULL;

	int _size = size + 1;//new size

	temp = new Student[size + 1];//new array with place for new student

	for (int i = 0; i < size; i++) {
		temp[i] = source[i];//copy from old to new
	}
	temp[size] = obj;

	
}
void Student::Insert_grades() {

	arr_kurs = new int[kurs];
	cout << "Enter grade of \n";
	for (int i = 0; i < kurs; i++) {
		cout << i + 1 << " course: ";
		cin >> arr_kurs[i];
	}
}
void Student::Print() const {
	cout << "Information of student:" << endl;
	cout << "\tName: " << this->name << "\n" <<
		"\tID: " << this->id << "\n" <<
		"\tBirhtdate: "; this->birht.Print();
	cout<<"\tCourses: " << this->kurs<<endl;
	
	for (int i = 0; i < kurs; i++) {
		cout <<"\t   "<<i + 1 << " grade: " << Get_mark(i) << endl;
	}
}

