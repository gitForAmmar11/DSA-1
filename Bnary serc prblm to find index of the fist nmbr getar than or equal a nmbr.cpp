#include <iostream>

int binarySearch(int arr[], int target, int start, int end) {
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] >= target) {
            if (mid == 0 || arr[mid - 1] < target) {
                return mid;
            } else {
                end = mid - 1;
            }
        } else {
            start = mid + 1;
        }
    }

    return -1; // If no element is greater than or equal to the target
}

int main() {
    int arr[] = {1, 3, 6, 7, 9, 11, 12};
    int target = 8;
    int size = sizeof(arr) / sizeof(arr[0]);

    int index = binarySearch(arr, target, 0, size - 1);

    if (index != -1) {
        std::cout << "Index of the first number greater than or equal to the target: " << index << std::endl;
    } else {
        std::cout << "No number greater than or equal to the target found." << std::endl;
    }

    return 0;
}

