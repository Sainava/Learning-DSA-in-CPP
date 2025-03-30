#include<iostream>
#include<algorithm>
using namespace std;

void reversearr(int arr[],int n){
            int start=0;
            int end=n-1;

            while(start<=end){
                swap(arr[start],arr[end]);
                start++;
                end--;
            }
}


void printarr(int arr[],int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){

    int arr[6]={1,4,0, 5,-2,15};
    int brr[5]={2,6,3,9,4};


    reversearr(arr,6);
    reversearr(brr,5);

    printarr(arr,6);
    printarr(brr,5);


    return 0;

}