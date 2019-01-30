
#ifndef _MYARR
#define _MYARR

#include <iostream>
#include <String.h>
using namespace std;

template <class T> 
class MyArr {
private:
	T* arr; // [] -> [],[],[] ... []
	int size;
	friend ostream& operator <<<T>(ostream& out, const MyArr& obj);
public:

	MyArr():arr(0),size(0){}
	MyArr(T arr[], int _size);
	~MyArr() { delete[] arr; }

	MyArr(const MyArr& obj);


	T& operator+=(const T& obj);
	T& operator[](int index);
	
	void Print_MyArr() const;

	void Print_Type() const; 

	int Find(const T& val);

	T* FindMax();

	T* FindMin();

	bool Is_Sorted();

	T SumOf_Arr();




};

#endif // !_MYARR

template <class T>
T MyArr<T>::SumOf_Arr() {
	T sum = 0;

	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}

	return sum;
}


template <class T>
bool MyArr<T>::Is_Sorted() {
	bool res = true;
	int index = 0;
	if (size == 0 || size == 1) return true;
	for (int i = 1; i < size; i++) {
		if (arr[index] <= arr[i]) {
			res = true;
		}
		else {
			return false;
		}
		index++;
	}
	return res;
}

template <class T>
T* MyArr<T>::FindMin() {
	T* min = new T;
	if (arr == NULL) return min = NULL;
	*min = arr[0];

	for (int i = 0; i < this->size; i++) {
		if ((*min) >= arr[i]) {
			(*min) = arr[i];
		}
	}
	return min;
}

template <class T>
T* MyArr<T>::FindMax() {
	T* max = new T;
	if (arr == NULL) {
		return max = NULL;
	}
	*max = arr[0];
	for (int i = 0; i < this->size; i++) {
		if (arr[i] >= *max) {
			*max = arr[i];
		}
	}
	return max;
}

template <class T>
T& MyArr<T>::operator[](int index) {
	if (index <0 || index>this->size) {
		throw "Invalid index!";
	}
	else {
		return arr[index];
	}
}

template <class T>
int MyArr<T>::Find(const T& val) {
	
	for (int i = 0; i < this->size; i++) {
		if (arr[i] == val)
			return i+1;
	}

	return -1;
}

template <class T>
void MyArr<T>::Print_Type() const {
	cout << "Current type of T is " << typeid(T).name() << endl;
}

template <class T>
void MyArr<T>::Print_MyArr() const {
	cout << "The values in MyArray..." << endl;
	for (int i = 0;i< this->size; i++) {
		cout << arr[i] << endl;
	}
}

template <class T>
ostream& operator <<  (ostream& out, const MyArr<T>& obj) {
	for (int i = 0; i < obj.size; i++) {
		out << obj.arr[i];
	}

	return out;
}

template<class T>
T& MyArr<T>::operator+=(const T& obj)
{
	T* temp = NULL;

	if (arr == NULL) {
		arr = new T[size + 1];
		arr[0] = obj;
		size++;
	}
	else {
			temp = new T[size + 1];
			for (int i = 0; i < size; i++) {
				temp[i] = arr[i];
			}
			temp[size] = obj;
			size++;

			delete[] arr;
			arr = temp;
	}
	return *arr;
}

template <class T>
 MyArr<T>::MyArr(T _arr[], int _size) : arr(NULL), size(_size) {
	 if (arr == NULL) {
		 arr = new T[size];
		 for (int i = 0; i < size; i++) {
			 arr[i] = _arr[i];
		 }

		 delete[] _arr;
		 _arr = NULL;

	}
}

 template<class T>
 MyArr<T>::MyArr(const MyArr & obj): size(obj.size)
 {
	 arr = new T[size];
	 for (int i = 0; i < size; i++) {
		 arr[i] = obj.arr[i];
	 }
 }

