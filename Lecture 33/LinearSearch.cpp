#include<iostream>
using namespace std;

bool linearSearch(int *arr,int size,int key ){
    if(size==0){
        return false;
    }
    if(arr[0]==key){
        return true;
    }
    return linearSearch(arr+1,size-1,key);
}


int main(){
    int arr[10] = {10, 2, 5, 7, 21};
    int key=2;
    if(linearSearch(arr, 5, key)){
        cout << "Element found in the array." << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
    return 0;
}