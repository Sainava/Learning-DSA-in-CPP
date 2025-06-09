#include<iostream>
using namespace std;


int partition(int *arr,int s,int e){
    int pivot=s;
    int count=0;

    for(int i=s+1;i<=e;i++){
        if(arr[i]<arr[pivot]){
            count++;
        }
    }

    int pivotIndex=s+count;

    swap(arr[pivot],arr[pivotIndex]);

    int i=s;
    int j=e;

    while(i<pivotIndex && j> pivotIndex){
        while(arr[i]<arr[pivotIndex]){
            i++;
        }
        while(arr[j]>arr[pivotIndex]){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }

    return pivotIndex;

}

void quickSort(int *arr,int s,int e){
    if (s>=e){
        return;
    }

    int p=partition(arr,s,e);
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}

int main(){
    int arr[] = {9 ,9, 9, 8, 2, 3, -6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Time Complexity: O(n log n)" << endl;
    cout << "Space Complexity: O(log n) for recursion stack" << endl;
    cout << "Worst Case Time Complexity: O(n^2) when the array is already sorted or reverse sorted" << endl;
    cout<< "QuickSort is not a stable sort, as it does not preserve the relative order of equal elements." << endl;
    cout << "QuickSort is an in-place sorting algorithm, meaning it requires only a small, constant amount of additional storage space." << endl;
    return 0;
}