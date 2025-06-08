#include<iostream>
using namespace std;

void insertionSort(int *arr,int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void RecursiveInsertionSort(int *arr, int n){
    if(n<=1){
        return;
    }
    RecursiveInsertionSort(arr, n - 1);
    int key=arr[n-1];
    int j=n-2;

    while(j>=0 && arr[j]>key){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
}
int main(){
   int arr[15] = {10, 2, 5, 7, 21,21,21,21, 1, 76, 52, 53, 0,69,81};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "Array before sorting: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    RecursiveInsertionSort(arr, size);
    cout << "Array after sorting: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "The array is sorted." << endl;
    return 0;

}