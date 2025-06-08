#include<iostream>
using namespace std;

void bubbleSort(int *arr, int n){
    if(n<=1){
        return ;
    }

    for (int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
    bubbleSort(arr, n-1);
}
    

int main(){
    int arr[13] = {10, 2, 5, 7, 21,21,21,21, 1, 76, 52, 53, 0};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "Array before sorting: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    bubbleSort(arr, size);
    cout << "Array after sorting: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "The array is sorted." << endl;
    return 0;
}