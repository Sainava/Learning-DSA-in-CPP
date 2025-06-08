#include<iostream>
#include<algorithm> // For std::sort
using namespace std;


bool BinarySearch(int *arr,int key,int s,int e){
    cout << "Searching in range: " << s << " to " << e << endl;
    for (int i = s; i <= e; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    if(s>e){
        return false;
    }
    int mid=s +(e-s)/2;
    if (arr[mid]==key ){
        return true ;
    }
    if(arr[mid]>key){
        return BinarySearch(arr,key,s,mid-1);
    } else {
        return BinarySearch(arr,key,mid+1,e);
    }
}
int main(){
    int arr[10] = {10, 2, 5, 7, 1,76,52,53,0,21};
    int key = 21;
    int size = sizeof(arr)/sizeof(arr[0]);
    // Sort the array before performing binary search
    sort(arr, arr + size); //sort(array_name, array_name + array_size);
    cout << "Sorted array: " ;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    BinarySearch(arr, key, 0, size - 1) ? cout << "Element found in the array." << endl : cout << "Element not found in the array." << endl;
    return 0;
}