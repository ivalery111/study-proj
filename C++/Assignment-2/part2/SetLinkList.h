
#ifndef _SET_LINK_LIST
#define _SET_LINK_LIST

#include <iostream>
#include <iomanip>
using namespace std;

class SetLinkList {

private:

	class Node {//--------------------------
		int data;
		Node* next;
	public:
		Node(int a) :data(a), next(NULL) {} //ctor
		Node(const Node&);//cctor
		friend class SetLinkList;
		void PrintNode() const;
	};//End of Node-------------------------

	Node* list_head; //pointer to beginning

	//methods
	void Print() const;
	bool IsEmpty() const;
	bool IsExist(int) const;
	


public:

	SetLinkList() : list_head(NULL) {} //{ list_head = NULL; } //ctor
	SetLinkList(const SetLinkList&);//cctor
	~SetLinkList();

	//operators
	SetLinkList& operator+=(int num);
	SetLinkList& operator-=(int num);
	SetLinkList& operator+(const SetLinkList& obj);
	SetLinkList& operator-(const SetLinkList& obj);
	SetLinkList& operator--();
	SetLinkList& operator--(int);
	bool operator==(const SetLinkList& obj);
	bool operator!=(const SetLinkList& obj);

	// I/O operator

	friend ostream& operator<<(ostream& out, const SetLinkList& obj);

};

#endif // !_SET_LINK_LIST

inline void SetLinkList::Node::PrintNode() const {
	if (data != NULL) {
		cout << setprecision(4) << data << " ";
	}
	else {
		cout << "Empty list" << endl;
	}
}



