#include <iostream>
using namespace std;

int binarySearch(int arr[], int target, int l, int h) {

    int result=0;
    while (l < h) {
        int mid = l + (h-l)/2;

        if (arr[mid] >= target) {
            result = mid;
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return result;
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements: ";
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    int target,l,h;
    cout << "Target: ";
    cin >> target;

    int index = binarySearch(arr, target, l, h);

    if (index != -1) {
        cout << "The index of the first number greater than or equal to " << target << " is: " << index;
    } else {
        cout << "There is no number greater than or equal to " << target << " in the array.";
    }

    return 0;
}

