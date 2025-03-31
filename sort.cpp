#include <iostream>
#include <cstdint>
#include "sort.h"

using namespace std;

void swap(int& a, int& b) noexcept {
    const int temp = a;
    a = b;
    b = temp;
}

void showArray(const int* arr, const int arrLength) {
    for (int i = 0; i < arrLength; i++) {
        cout << "arr[" << i << "]: ";
        cout << arr[i] << endl;
    }
}

void SortInsert(int* arr, const int arrLength) {
    for (int i = 1; i < arrLength; i++) {
        const int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    showArray(arr, arrLength);
}


void SortSelect(int* arr, const int arrLength) {
    for (int i = 0; i < arrLength - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < arrLength; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }

    showArray(arr, arrLength);
}

void SortMinmax(int* arr, const int arrLength) {
    for (int i = 0; i < arrLength / 2; i++) {
        int minIndex = i;
        int maxIndex = i;

        for (int j = i; j < arrLength - i; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }

        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }

        if (maxIndex != arrLength - i - 1) {
            swap(arr[arrLength - i - 1], arr[maxIndex]);
        }
    }

    showArray(arr, arrLength);
}

void SortShow(const int* arr, const int arrLength) {
    const auto used = new bool[arrLength] {false};

    for (int i = 0; i < arrLength; i++) {
        int min = INT_MAX;
        int minIndex = -1;

        for (int j = 0; j < arrLength; j++) {
            if (!used[j] && arr[j] < min) {
                min = arr[j];
                minIndex = j;
            }
        }

        if (minIndex == -1) break;

        cout << min << " ";
        used[minIndex] = true;
    }

    delete[] used;
}


void SortMerge(int* arr, const int arrLength) {

}

void SortShell(int* arr, const int arrLength) {

}

void SortQuick(int* arr, const int arrLength) {

}

void SortHeap(int* arr, const int arrLength) {

}

void SortBucket(int* arr, const int arrLength) {

}

void SortRadix(int* arr, const int arrLength) {

}