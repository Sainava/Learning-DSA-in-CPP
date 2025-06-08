#include<iostream>
using namespace std;

int sumArr(int *arr,int size){
    if (size==0){
        return 0;
    }
    if (size==1){
        return arr[0];
    }
    int sum= arr[0]+ sumArr(arr+1,size-1);
    return sum;

}

int main(){
    int arr[10] = {10, 2, 10, 7, 21};
    cout << "The sum of the array is: " << sumArr(arr, 5) << endl;
    return 0;
}