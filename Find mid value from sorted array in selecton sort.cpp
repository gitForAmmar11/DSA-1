#include <iostream>
using namespace std;

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}
void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {

      if (array[i] < array[min_idx])
        min_idx = i;
    }

    int temp = array[min_idx];
    array[min_idx] = array[step];
    array[step]= temp;
  }
}
double median(int data[], int n){
    int median;
    if(n%2 == 0){
        median = data[n/2];
        cout << "Median: " << median <<endl;
    }
    else{
        median = data[n/2];
        cout << "Median: " << median << endl;
    }
}

int main() {
    int size;
    cout << "Enter Array Size: ";
    cin >> size;

  int data[size];
  size = sizeof(data) / sizeof(data[0]);
  cout << "Enter Array Element: ";
  for(int i = 0; i<size; i++){
    cin >> data[i];
  }
  selectionSort(data, size);
  cout << "Sorted array in Ascending Order:\n";
  printArray(data, size);

  median (data,size);
}
