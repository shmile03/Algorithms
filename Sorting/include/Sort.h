#include <iostream>
#include <vector>

#pragma once

template <class T>
class Sort {
private:

	static void swap(T* a, T* b);
    static void merge(std::vector<T>& a, int l, int m, int r);
    static void heapify(std::vector<T>& a, int n, int i);
    static int partition(std::vector<T>& a, int low, int high);

public:

	Sort() {};

	static void bubbleSort(std::vector<T>& a);
    static void insertionSort(std::vector<T>& a);
    static void selectionSort(std::vector<T>& a);
    static void mergeSort(std::vector<T>& a, int l, int r);
    static void heapSort(std::vector<T>& a, int n);
    static void quickSort(std::vector<T>& a, int low, int high);
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

template<class T>
void Sort<T>::heapify(std::vector<T>& a, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest]) {
        largest = l;
    }
    if (r < n && a[r] > a[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

template<class T>
void Sort<T>::heapSort(std::vector<T>& a, int n) {
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(a, n, i);
    }
    for (int i = n - 1; i >= 0; --i) {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

template<class T>
int Sort<T>::partition(std::vector<T>& a, int low, int high) {
    T pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (a[j] < pivot) {
            ++i;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return i + 1;
}

template<class T>
void Sort<T>::quickSort(std::vector<T>& a, int low, int high) {
    int tmp = 0;
    if (low < high) {
        tmp = partition(a, low, high);

        quickSort(a, low, tmp - 1);
        quickSort(a, tmp + 1, high);
    }
}