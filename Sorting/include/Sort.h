#include <iostream>
#include <vector>

#pragma once

template <class T>
class Sort {
private:

	static void swap(T* a, T* b);
    static void merge(std::vector<T>& a, int l, int m, int r);

public:

	Sort() {};

	static void bubbleSort(std::vector<T>& a);
    static void insertionSort(std::vector<T>& a);
    static void selectionSort(std::vector<T>& a);
    static void mergeSort(std::vector<T>& a, int l, int r);
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

template<class T>
void Sort<T>::merge(std::vector<T>& a, int l, int m, int r) {
	int tmp1 = m - l + 1;
	int tmp2 = r - m;

	std::vector<T> L(tmp1), R(tmp2);

	for (int i = 0; i < tmp1; ++i) {
		L[i] = a[l + i];
	}
	for (int j = 0; j < tmp2; ++j) {
		R[j] = a[m + 1 + j];
	}

	int i = 0, j = 0, k = l;

	while (i < tmp1 && j < tmp2) {
		if (L[i] <= R[j]) {
			a[k] = L[i];
			++i;
		}
		else {
			a[k] = R[j];
			++j;
		}
		++k;
	}

	while (i < tmp1) {
		a[k] = L[i];
		++i;
		++k;
	}

	while (j < tmp2) {
		a[k] = R[j];
		++j;
		++k;
	}
}

template<class T>
void Sort<T>::mergeSort(std::vector<T>& a, int l, int r) {
    int m = 0;
    if (l < r) {
        m = l + (r - l) / 2;

        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        merge(a, l, m, r);
    }
}