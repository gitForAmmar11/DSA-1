#include <iostream>
using namespace std;


int BinarySearch(int array[],int l,int h,int x){
    while(l<h){
        int mid = l+(h-l)/2;
        if(array[mid]>=x){
           int result = mid;
            h = mid-1;
        }
        else if(array[mid]<x){
            l= mid+1;
        }
    }
    return -1;

}

int main()
{
  int size;
  cout << "Enter Array Size: ";
  cin >> size;
  int array[size];

  cout << "Enter array element: ";
  for(int i = 0; i<size; i++){
    array[i] = i;
    cin >> array[i];
  }
  int key;
  cout << "Key: ";
  cin >> key;

  cout << binarySearch(array,size,n,key)

}

