
#include <iostream>
using namespace std;

template <class T>

T* Remove(T arr[], int size, T val) {

	T* temp = new T[size];
	int count = 0;

	//calculate and copy elements that dont equal to 'val'
	for (int i = 0; i < size; i++) {
		if (arr[i] != val) {
			temp[count]=arr[i];
			count++;
		}	
	}
	T* arr_new = new T[count];

	for (int i = 0; i < count; i++) {
		arr_new[i] = temp[i];
		cout << arr_new[i] << " , ";
	}
	

	delete[] temp;
	temp = NULL;

	return arr_new;
}

int main() {
	long* ptr;
	int arr[9] = { 5,5,44,5,44,6,77,5,6 };
	float arr2[4] = { 1.2,1.5,1.6,1.8 };
	long arr3[3] = { 1213432,43543423,43245324 };

	Remove(arr, 9, 5);
	Remove<float>(arr2, 4, 1.2);
	Remove<long>(arr3, 3, 1213432);


	return 0;
}