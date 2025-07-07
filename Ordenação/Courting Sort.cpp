#include <iostream>
#include <vector>
#include <algorithm>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void countingSort(int arr[], int size) {
    if (size == 0) {
        return;
    }
    int maxElement = *std::max_element(arr, arr + size);

    int* count = new int[maxElement + 1]();

    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    int arrayIndex = 0;
    for (int i = 0; i <= maxElement; i++) {
        while (count[i] > 0) {
            arr[arrayIndex] = i;
            arrayIndex++;
            count[i]--;
        }
    }
    
    delete[] count;
}

int main() {
    int data[] = {4, 2, 2, 8, 3, 3, 1, 9, 5, 4, 9, 5};
    int n = sizeof(data) / sizeof(data[0]);

    std::cout << "Array original: " << std::endl;
    printArray(data, n);

    countingSort(data, n);

    std::cout << "\nArray ordenado com Counting Sort: " << std::endl;
    printArray(data, n);

    return 0;
}