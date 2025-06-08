#include<iostream>
#include<algorithm> // For std::swap
using namespace std;

void selectionSort(int *arr,int s,int n){
    if(s>=n-1){
        return ;
    }

    int minIndex=s;
    for (int i=s+1;i<n;i++){
        if(arr[i]<arr[minIndex]){
            minIndex=i;
        }
    }
    swap(arr[s], arr[minIndex]);

    selectionSort(arr, s + 1, n);
}

int main(){
   int arr[13] = {10, 2, 5, 7, 21,21,21,21, 1, 76, 52, 53, 0};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "Array before sorting: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    selectionSort(arr, 0,size);
    cout << "Array after sorting: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "The array is sorted." << endl;
    return 0;

}