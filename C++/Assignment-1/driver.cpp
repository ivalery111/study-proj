
#include "MyDate.h"
#include "Student.h"
#include "Worker.h"

#define NAME_SIZE 20

using namespace std;


bool check(Student** stud , int size_stud , Worker** work,int size_work, char* _id ){
	//check id in students
	for (int i = 0; i < size_stud; i++) {
		if (strcmp(stud[i]->id, _id) == 0) // 0 - exist
			return false;
	}
	//check id in works
	for (int i = 0; i < size_work; i++) {
		if (strcmp(work[i]->id, _id) == 0)
			return false;
	}
	return true;
}

int birthday(Student** stud, int size_stud, Worker** work, int size_work, MyDate& obj) {
	int count = 0;

	for (int i = 0; i < size_stud; i++) {
		if (stud[i]->Get_Birth() == obj) {
			cout << "Name of student is " << stud[i]->Get_Name();
			cout << " and her age is " << stud[i]->birht.Get_Year() - 2000 << endl;
			count++;
		}
	}

	for (int i = 0; i < size_work; i++) {
		if (work[i]->Get_Birth() == obj) {
			cout << "Name of worker is " << work[i]->Get_Name();
			cout << " and her age is " << work[i]->birht.Get_Year() - 2000 << endl;
			count++;
		}
	}


	return count;
}



//statics objects
MyDate* MyDate::_max = NULL;
MyDate* MyDate::_min = NULL;
//--------------------------

void PrintMenu() {
	cout << "\n1 - Add New Student" << endl;
	cout << "2 - Add New Worker" << endl;
	cout << "3 - Student's update" << endl;
	cout << "4 - Worker Update" << endl;
	cout << "5 - Print information about Students and Workers" << endl;
	cout << "6 - Min/Max Birthday" << endl;
	cout << "7 - Birthdays" << endl;
	cout << "8 - Exit\n" << endl;
}

int main() {

	Student **students = NULL;	 int stud_size = 0;//count of all students
	Worker **workers = NULL;	 int work_size = 0;//count of all workers\

	MyDate *date = NULL;

	int choice = 0, year = 0, month = 0, day = 0, tarif = 0,index=0,grade =0;

	char name[20], id[10];

	while (choice != 8)
	{
		PrintMenu();
		cin >> choice;

		switch (choice)
		{
		case 1: {//Add Student
			Student **temp = new Student*[stud_size + 1]; //temporary array of students with add place for new student
			bool flag = true;
			for (int i = 0; i < stud_size; i++) {
				temp[i] = students[i]; //copy adresses from old array to temporary
			}
			do {
				cout << "Please enter:" << endl;
				cout << "Name: "; cin >> name;
				cout << "ID: "; cin >> id;
				cout << "Year: "; cin >> year;
				cout << "Month: "; cin >> month;
				cout << "Day: "; cin >> day;

				flag = check(students, stud_size, workers, work_size, id);
				if (flag == false) cout << "This ID already taken, enter another ID!" << endl;
			} while (!flag);
			temp[stud_size] = new Student(name, id, year, month, day);//Put new student to last place in temp array
			delete[] students; //delete origanl array
			stud_size++; // ++ - due to new student
			students = new Student*[stud_size];
			students = temp; //new array of student get address of temp array of students
			temp = NULL; // without 'temp = NULL' students null
			delete[] temp;

			break;

		}

		case 2: {//Add Worker
			Worker **temp = new Worker*[work_size + 1]; //temporary array of students with add place for new student
			bool flag = true;
			for (int i = 0; i < work_size; i++) {
				temp[i] = workers[i]; //copy adresses from old array to temporary
			}
			do {
				cout << "Please enter:" << endl;
				cout << "Name: "; cin >> name;
				cout << "ID: "; cin >> id;
				cout << "Tariff: "; cin >> tarif;
				cout << "Year: "; cin >> year;
				cout << "Month: "; cin >> month;
				cout << "Day: "; cin >> day;

				flag = check(students, stud_size, workers, work_size, id);
				if (flag == false) cout << "This ID already taken, enter another ID!" << endl;
			} while (!flag);
			temp[work_size] = new Worker(name, id, year, month, day,tarif);//Put new student to last place in temp array
			delete[] workers; //delete origanl array
			work_size++; // ++ - due to new worker
			workers = new Worker*[stud_size];
			workers = temp; //new array of worker get address of temp array of workers
			temp = NULL; // without 'temp = NULL' students null
			delete[] temp;

			break;
		}

		case 3: {//Student's update
			if (students == NULL) { cout << "You need to create minimun one student!\n"; break; }
			cout << "\nEnter index of student: "; cin >> index;
			if (index<0 || index>stud_size) {
				cout << "Incorrect index of student!"<<endl; break;
			}
			cout << "Enter new grade: "; cin >> grade;
			students[index]->Add_grade(grade);
			break;
		}

		case 4: {//Worker's Update
			if (workers == NULL) { cout << "You need to create minimun one worker!\n"; break; }

			cout << "\nEnter index of worker: "; cin >> index;
			if (index<0 || index>work_size) { cout << "Incorrect index of worker!\n"; break; }
			workers[index]->Set_work_hours();
		}

		case 5: {
			//Students is first
			if (students == NULL) { cout << "You need to create minimun one student!\n"; break; }

			for (int i = 0; i < stud_size; i++) {
				students[i]->Print();
			}
			if (workers == NULL) { cout << "You need to create minimun one worker!\n"; break; }
			for (int i = 0; i < work_size; i++) {
				workers[i]->Print();
			}

			break;
		}

		case 6: {//not complete
			date = new MyDate();
			date = &students[0]->Get_Birth();

			for (int i = 0; i < stud_size; i++) {
				date->is_before(students[i]->Get_Birth());
			}
			date->ShowMinMax();
			break;
		}
		case 7: {
			cout << "Please enter:" << endl;
			cout<<"\tYear: "; cin >> year;
			cout << "\tMonth: "; cin >> month;
			cout << "\tDay: "; cin >> day;
			date = new MyDate(year, month, day);
			cout << birthday(students, stud_size, workers, work_size, *date)<<" people have the same birthday"<<endl;

			delete date;
			break;
		}

		case 8: {
			//Students is first
			for (int i = 0; i < stud_size; i++) {
				delete students[i];
			}
			for (int i = 0; i < work_size; i++) {
				delete workers;
			}
			//----------------------------------------------------------------------------------------

			delete[] students;
			delete[] workers;

			break;
		}

		default:
			break;
		}
	}
	return 0;
}