#include<iostream>
using namespace std;

bool isSorted(int *arr,int size){
    if(size==0 || size==1){
        return true;
    }

    if(arr[0]>arr[1]){
        return false;
    }
    return isSorted(arr+1,size-1);
}
int main(){
    int arr[10] = {1, 2, 5, 7, 21};
    cout <<endl;
    isSorted(arr, 5) ? cout << "Array is sorted" : cout << "Array is not sorted";

    return 0;

}