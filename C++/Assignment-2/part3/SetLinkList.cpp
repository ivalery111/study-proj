#include "SetLinkList.h"

//========     class NODE    =======

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// copy constructor
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

SetLinkList::Node::Node(const Node& obj) : data(obj.data) {

	if (obj.next == NULL) {
		next = NULL;
	}
	else {
		next = new Node(*(obj.next));
	}
	

}


//====================================




//========     class SETLINKLIST    =======

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// copy constructor
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SetLinkList::SetLinkList(const SetLinkList& obj) {//?

	if (obj.list_head == NULL) {
		list_head = NULL;
	}
	else {
		list_head = new Node(*(obj.list_head));
		Node* current = obj.list_head->next;
		while (current) {
			*this += current->data;
			current = current->next;
		}
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// dctor
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//Algorithm:
// 1. Checking that list not empty
// 2. List not empty, than creating 2 'help' nodes: *current and *temp
// 3. current get addres of first element in list
// 4. Creating loop 'while(current != NULL)'
// 5. 'temp = current' doing this in order to save address of next Node
// 6. Next step for current: 'current = current->next'
// 7. Delete temp
SetLinkList::~SetLinkList() {
	if (IsEmpty() == false) {
		Node* current, *temp;
		current = list_head;

		while (current != NULL) {
			temp = current;
			current = current->next;
			delete temp;
		}

	}
}



///////////////////// operators ///////////////////// 

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// operator +=
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SetLinkList& SetLinkList::operator+=(int num) {

	Node* _new_node = new Node(num);

	//check if Node with the same 'num' exist in list
	if (IsExist(num)) {
		return *this;//if exist, exiting from method
	}
	if (IsEmpty()==false) {
		_new_node->next = list_head;
	}
	list_head = _new_node;
	return *this;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// operator -= (delete)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//Options:

// 1. Empty list
// 2. Number not exist
// 3. Number is first
// 4. Number is last
// 5. Number in list
SetLinkList& SetLinkList::operator-=(int num) {

	Node* current = list_head, *prev = NULL;

	if (IsEmpty()) {//Empty list
		cout << "List is empty!" << endl;
		return *this;
	}

	if (current->data == num) {//Searched number is first
		list_head = list_head->next;
		delete current;
		return *this;
	}

	while (current != NULL) {// Number in list or last

		if (current->data == num) {
			prev->next = current->next;
			delete current;
			current = NULL;
			break;
		}
		prev = current;
		current = current->next;
	}

	return *this;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// operator +
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SetLinkList& SetLinkList::operator+(const SetLinkList& obj) {

	SetLinkList* list3 = new SetLinkList();

	Node* current = list_head;

	//add first list
	while (current != NULL) {
		*list3 += current->data;
		current = current->next;
	}

	//add second list
	current = obj.list_head;
	while (current != NULL) {
		*list3 += current->data;
		current = current->next;
	}
	return *list3;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// operator -
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SetLinkList& SetLinkList::operator-(const SetLinkList& obj) {
	//list1 = this = basis!
	SetLinkList* list3 = new SetLinkList();
	Node* current = list_head;

	while (current != NULL) {
		if (obj.IsExist(current->data) == false) {
			*list3 += current->data;
		}
		current = current->next;
	}
	return *list3;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// operator -- (prefix)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SetLinkList& SetLinkList::operator--() {
	Node* pDel = NULL;
	if (IsEmpty() == false) {
		pDel = list_head;//pDel point to first element
		list_head = list_head->next;//next elemnt became new list_head
		delete pDel;
		pDel = NULL;
	}
	return *this;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// operator -- (postfix)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SetLinkList& SetLinkList::operator--(int) {
	Node* current = list_head, *prev=NULL;

	if (IsEmpty() == false) {
		while (current != NULL) {
			if (current->next == NULL) {
				prev->next = current->next;
				delete current;
				current = NULL;
				break;
			}

			prev = current;
			current = current->next;
		}
	}
	return *this;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// operator == (bool)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

bool SetLinkList::operator==(const SetLinkList& obj) {
	bool res = false;
	Node* current1 = list_head,		//pointer to first list
		*current2 = obj.list_head;	//ptr to second list

	if (IsEmpty() == false && obj.IsEmpty() == false) { //if both list not empty, then...

		while (current1 != NULL || current2 != NULL) {
			if ((current1 == NULL && current2 != NULL) || (current1 != NULL && current2 == NULL)) {
				return false;
			}
			else {
				if (obj.IsExist(current1->data)) {
					res = true;
				}
				else {
					return false;
				}
			}
			current1 = current1->next;
			current2 = current2->next;
		}
		return res;
	}
	return res;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// operator != (bool)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

bool SetLinkList::operator!=(const SetLinkList& obj) {

	bool res = false;
	Node* current1 = list_head,
		*current2 = obj.list_head;

	if (IsEmpty() == false && obj.IsEmpty() == false) {

		while (current1 != NULL || current2 != NULL) {
			if ((current1 == NULL && current2 != NULL) || (current1 != NULL && current2 == NULL)) {
				return true;
			}
			else {
				if (obj.IsExist(current1->data)) {
					res = false;
				}
				else {
					return true;
				}
			}


			current1 = current1->next;
			current2 = current2->next;
		}
		return res;
	}
}



//////////////////////////////////////////////////////////////////////
// I/O Operator
//////////////////////////////////////////////////////////////////////
ostream & operator<<(ostream & out, const SetLinkList & obj)
{
	if (obj.IsEmpty()) {
		cout << "List is Empty" << endl;
	}
	obj.Print();
	return out;
}



//////////////////////////////////////////////////////////////////////
// Methods (private)
//////////////////////////////////////////////////////////////////////

// true = exist
// false = not exist
bool SetLinkList::IsExist(int num) const {

	//create new node with:
	// data = num
	// next = NULL
	Node* _new_node = new Node(num);

	if (IsEmpty()) {//if list empty, then...
		return false; //not exist 'num' in list
	}
	else {//list not empty, then need check each element 

		//creating of 'help' node that get address of first element in list
		Node* temp = list_head;

		while (temp != NULL) {
			if (temp->data == _new_node->data) {
				return true;
			}
			else {
				temp = temp->next;//condition of next step
			}
		}
	}
	return false;
}

// true - empty
// false = not empty
bool SetLinkList::IsEmpty() const {
	return list_head == NULL;
}

void SetLinkList::Print() const {

	Node* temp = list_head;

	while (temp != NULL) {
		if (temp->data != NULL) {
			temp->PrintNode();
		}

		temp = temp->next;
	}
	cout << endl;
}


//////////////////////////////////////////////////////////////////////
// Methods (public)
//////////////////////////////////////////////////////////////////////

void SetLinkList::Reverse() {
	//cout << list_head << endl;
	int count = 1;
	Node* prev = NULL,
		*current = list_head,
		*next=NULL;

	while (current != NULL) {
	//	cout << "Lap [" << count << "]:Start... " <<*this<< endl;
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	//	cout << "Lap [" << count << "]:End...\nList: " << *this << endl;
	count++;
		//cout << *this << endl;
	//cout << "prev.data = " << prev->data << " , prev->next->data = "; cout << (prev->next->data) << endl;
	}
	list_head = prev;
	//cout << "Count = " << count << endl;
}


