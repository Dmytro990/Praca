#include <iostream>
#include <cstdlib>
#include <ctime>

const int ARRAY_SIZE = 10;

struct Range {
    int x;
    int y;
};

void wypelnijTab(int arr[], int size) {
    std::srand(std::time(nullptr));

    for (int i = 0; i < size; ++i) {
        arr[i] = std::rand() % 100; 
    }
}

void drukujTab(const int arr[], int size) {
    std::cout << "Tablica: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void sortowanie_babelkowe(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void merge(int arr[], int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int* left = new int[n1];
    int* right = new int[n2];

    for (int i = 0; i < n1; ++i) {
        left[i] = arr[start + i];
    }
    for (int j = 0; j < n2; ++j) {
        right[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        arr[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
    }

    while (i < n1) {
        arr[k++] = left[i++];
    }

    while (j < n2) {
        arr[k++] = right[j++];
    }

    delete[] left;
    delete[] right;
}

void sortowanie_przez_scalanie(int arr[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;

        sortowanie_przez_scalanie(arr, start, mid);
        sortowanie_przez_scalanie(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }
}

int main() {
    int myArray[ARRAY_SIZE];

    // Sortowanie bąbelkowe
    wypelnijTab(myArray, ARRAY_SIZE);
    drukujTab(myArray, ARRAY_SIZE);

    sortowanie_babelkowe(myArray, ARRAY_SIZE);

    drukujTab(myArray, ARRAY_SIZE);

    // Sortowanie przez scalanie
    wypelnijTab(myArray, ARRAY_SIZE);
    drukujTab(myArray, ARRAY_SIZE);

    sortowanie_przez_scalanie(myArray, 0, ARRAY_SIZE - 1);

    drukujTab(myArray, ARRAY_SIZE);

    return 0;
}
