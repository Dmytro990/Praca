#include <iostream>
#include <cstdlib>
#include <ctime>

#define ARRAY_SIZE 10
#define RANGE_MIN 1
#define RANGE_MAX 100

struct Range {
    int x;
    int y;
};

void fillArray(int arr[], int size, const Range& range) {
    std::srand(std::time(0)); 

    for (int i = 0; i < size; ++i) {
        arr[i] = std::rand() % (range.y - range.x + 1) + range.x;
    }
}

int main() {
    const int n = ARRAY_SIZE;

    Range range;
    range.x = RANGE_MIN;
    range.y = RANGE_MAX;

    int myArray[n];

    fillArray(myArray, n, range);

    std::cout << "Filled Array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}