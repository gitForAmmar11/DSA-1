#include <iostream>

void sortEvenOdd(int arr[], int size) {
    // Partition the array into even and odd numbers
    int i = -1;
    int j = size;

    while (true) {
        do {
            i++;
        } while (arr[i] % 2 == 0);

        do {
            j--;
        } while (arr[j] % 2 != 0);

        if (i >= j) {
            break;
        }

        std::swap(arr[i], arr[j]);
    }

    // Sort even numbers in ascending order
    for (int k = 0; k <= i - 1; k++) {
        for (int l = k + 1; l <= i; l++) {
            if (arr[k] > arr[l]) {
                std::swap(arr[k], arr[l]);
            }
        }
    }

    // Sort odd numbers in descending order
    for (int m = i + 1; m < size - 1; m++) {
        for (int n = m + 1; n < size; n++) {
            if (arr[m] < arr[n]) {
                std::swap(arr[m], arr[n]);
            }
        }
    }
}

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int arr[size];
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    sortEvenOdd(arr, size);

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
