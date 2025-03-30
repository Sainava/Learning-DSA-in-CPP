#include<iostream>
using namespace std;

int binarysearch(int arr[],int n,int k){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;

    while (s<e){
        if(arr[mid]==k){
            return mid;
        }

        if(arr[mid]<k){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    
    return -1;
}

int main(){
    int arr[5]={1,2,3,7,9};
    int k = 1;
    int index = binarysearch(arr, 5, k);
    
    if (index != -1) {
        cout << "The index of the given element is: " << index << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}