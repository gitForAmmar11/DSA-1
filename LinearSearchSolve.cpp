#include <iostream>
using namespace std;

int linearSearchSum(int arr[], int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            if (i + 3 < size) {
                int sum = arr[i] + arr[i + 1] + arr[i + 2] + arr[i + 3];
                return sum;
            } else {
                // If there are not enough elements following the number
                return -1;
            }
        }
    }

    // If the number is not found in the array
    return -1;
}

int main() {
    int size;
    cout << "Enter array size: ";
    cin >> size;
    int arr[size];
    cout << "Enter array elements: ";
    for (int i=0; i<size; i++){
        cin >> arr[i];
    }
    int num;
    cout << "Target: ";
    cin >> num;

    int result = linearSearchSum(arr, size, num);

    if (result != -1) {
        cout << "Output: " << result << endl;
    } else {
        cout << "Number not found in the array or not enough numbers following the given number." << endl;
    }

    return 0;
}


