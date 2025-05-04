#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {

    int count = 0;
    int loop = 0;
    int swapped = 0;

    for(int i=0; i<n-1; i++){

        for(int j=0; j<n-1-i; j++){
            if (arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                count++;
                swapped = 1;
            }
        }
        if(swapped==0){
            break;
        }
        loop++;
    }
    cout << "The number of swapping: " <<count <<endl;
    cout << "The number of loop running: "<<loop <<endl;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                count++;
            }
        }
        if(!swapped)
            break;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter array size: "<< endl;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << "Original array: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
