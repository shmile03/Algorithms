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
    static void insertionSort(std::vector<T>& a);
    static void selectionSort(std::vector<T>& a);
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

template<class T>
void Sort<T>::insertionSort(std::vector<T>& a) {
    T tmp;
    int j = 0;
    for (int i = 1; i < a.size(); ++i) {
        tmp = a[i];
        for (j = i - 1; j >=0 && (a[j] > tmp); --j) {
            a[j + 1] = a[j];
        }
        a[j + 1] = tmp;
    }
}

template<class T>
void Sort<T>::selectionSort(std::vector<T>& a) {
    T tmpMin = 0;
    for (int i = 0; i < a.size() - 1; ++i) {
        tmpMin = i;
        for (int j = i + 1; j < a.size(); ++j) {
            if (a[j] < a[tmpMin]) {
                tmpMin = j;
            }
        }
        swap(&a[tmpMin], &a[i]);
    }
}