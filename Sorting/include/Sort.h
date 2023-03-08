#include <iostream>
#include <vector>

#pragma once

template <class T>
class Sort {
private:

	static void swap(T* a, T* b);

public:

	Sort() {};

	static void bubbleSort(std::vector<T>& a);
};

template<class T>
void Sort<T>::swap(T* a, T* b) {
	T tmp = *a;
	*a = *b;
	*b = tmp;
}

template<class T>
void Sort<T>::bubbleSort(std::vector<T>& a) {
	for (int i = 0; i < a.size() - 1; ++i) {
		for (int j = 0; j < a.size() - 1 - i; ++j) {
			if (a[j] > a[j + 1]) {
				swap(&a[j], &a[j + 1]);
			}
		}
	}
}