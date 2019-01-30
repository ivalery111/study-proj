#include "SetLinkList.h"
using namespace std;

int main() {

	
	
	SetLinkList list1;
	for (int i = 20; i < 100; i += 30) {
		list1 += i;
	}
	cout << " list1: " << list1 << endl;
	SetLinkList list2(list1);
	list2 += 200;
	list2 += 300;
	cout << " list2: " << list2 << endl;
	for (int i = 25; i < 60; i++) {
		list1 -= i;
	}
	list1 += 55;
	cout << endl << endl;
	cout << " list1: " << list1 << endl;
	cout << " list2: " << list2 << endl;

	SetLinkList temp;
	temp = list1 + list2;
	cout << " Union: " << temp << endl;

	cout << endl << endl;
	cout << " list1: " << list1 << endl;
	cout << " list2: " << list2 << endl;

	temp = list1 - list2;
	cout << " ---------Minus: " << temp << endl;
	cout << endl << endl;
	SetLinkList list3(list2);
	cout << " prefix -- : ";
	cout << "list3: " << --list3 << endl;
	cout << " postfix -- : ";
	cout << "list3: " << list3-- << endl;

	cout << endl << endl;
	SetLinkList list4;

	list4 += 50;
	list4 += 200;
	list4 += 300;
	
	

	cout << "list2 :" << list2 << endl;
	cout << "list4 :" << list4 << endl;
	if (list4 == list2) {
		cout << "equals";
	}
	else {
		cout << "not equals" << endl;
	}
	list2 -= 20;
	list4 += 80;
	cout << "list2 :" << list2 << endl;
	cout << "list4 :" << list4 << endl;
	if (list4 == list2) {
		cout << "equals" << endl;
	}
	else {
		cout << "not equals" << endl;
	}

	cout << "list1 :" << list1 << endl;
	cout << "list4 :" << list4 << endl;

	if (list1 != list4) {
		cout << "not equal" << endl;
	}
	else {
		cout << "equals" << endl;
	}
	

	//Driver of bonus
	/*
	SetLinkList list4;
	list4 += 60;
	list4 += 70;
	list4 += 80;
	list4 += 90;
	list4 += 100;
	cout << "List4: " << list4 << endl;
	list4.Reverse();
	cout << "List4: " << list4 << endl;
	*/




	return 0;
}