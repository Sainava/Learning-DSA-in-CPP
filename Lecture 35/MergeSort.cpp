#include<iostream>
using namespace std;

void Merge(int *arr,int s,int e){
    int mid=s + (e-s)/2;

    int len1= mid-s +1;
    int len2= e - mid;

    int *first=new int[len1];
    int *second =new int[len2];

    int k=s;
    for(int i=0;i<len1;i++){
        first[i]=arr[k++];
    }

    k=mid+1;
    for (int i=0;i<len2;i++){
        second[i]=arr[k++];
    }

    // Merge two sorted arrays
    int index1=0;
    int index2=0;

    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[s++]=first[index1++];
        }else{
            arr[s++]=second[index2++];
        }
        }
        while(index1<len1){
            arr[s++]=first[index1++];
        }
        while(index2<len2){
            arr[s++]=second[index2++];
        }

        delete [] first;
        delete [] second;
    }




void MergeSort(int *arr, int s, int e){
    if (s>=e){
        return ;
    }
    int mid= s + (e-s)/2;
    MergeSort(arr,s,mid);
    MergeSort(arr,mid+1,e);

    Merge(arr,s,e);
}

int main(){
   int arr[] = {10, 2, 5, 7, 21,21,21,21, 1, 76, 52, 53, 0};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "Array before sorting: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    MergeSort(arr, 0, size - 1);
    cout << "Array after sorting: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "The array is sorted." << endl;
    return 0;
}