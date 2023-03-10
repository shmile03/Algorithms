#include <gtest.h>
#include <time.h>
#include <vector>
#include "Sort.h"

#define LENGTH 1000

TEST(Sort, bubble_sorting_happened) {

    std::vector<int> vector(LENGTH);

    srand(time(NULL));
    int tmp = 0;
    for (int i = 0; i < LENGTH; ++i) {
        tmp = rand() % 1000;
        vector.push_back(tmp);
    }

    Sort<int>::bubbleSort(vector);

    bool flag = true;
    for (int i = 0; i < LENGTH - 1; ++i) {
        if (vector[i + 1] < vector[i]) {
            flag = false;
            break;
        }
    }

	EXPECT_EQ(true, flag);
}

TEST(Sort, insertion_sorting_happened) {

    std::vector<int> vector(LENGTH);

    srand(time(NULL));
    int tmp = 0;
    for (int i = 0; i < LENGTH; ++i) {
        tmp = rand() % 1000;
        vector.push_back(tmp);
    }

    Sort<int>::insertionSort(vector);

    bool flag = true;
    for (int i = 0; i < LENGTH - 1; ++i) {
        if (vector[i + 1] < vector[i]) {
            flag = false;
            break;
        }
    }

    EXPECT_EQ(true, flag);
}

TEST(Sort, selection_sorting_happened) {

    std::vector<int> vector(LENGTH);

    srand(time(NULL));
    int tmp = 0;
    for (int i = 0; i < LENGTH; ++i) {
        tmp = rand() % 1000;
        vector.push_back(tmp);
    }

    Sort<int>::selectionSort(vector);

    bool flag = true;
    for (int i = 0; i < LENGTH - 1; ++i) {
        if (vector[i + 1] < vector[i]) {
            flag = false;
            break;
        }
    }

    EXPECT_EQ(true, flag);
}

TEST(Sort, merge_sorting_happened) {

    std::vector<int> vector(LENGTH);

    srand(time(NULL));
    int tmp = 0;
    for (int i = 0; i < LENGTH; ++i) {
        tmp = rand() % 1000;
        vector.push_back(tmp);
    }

    Sort<int>::mergeSort(vector, 0, LENGTH - 1);

    bool flag = true;
    for (int i = 0; i < LENGTH - 1; ++i) {
        if (vector[i + 1] < vector[i]) {
            flag = false;
            break;
        }
    }

    EXPECT_EQ(true, flag);
}