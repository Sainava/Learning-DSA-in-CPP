#include<iostream>
//#include<algorithm>
using namespace std;

void printarr(int arr[],int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int  sort01(int arr[],int n){

    int left=0;
    int right=n-1;

    while(left < right){

        while(arr[left]==0){
            left++;
        }
        
        

        while(arr[right]==1){
            right--;
        }

        //arr[left]=1 and arr[right]=0

        if (left<right){
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
    }
}

int main(){

    int arr[8]={1,1,0,0,0,0,1,1};

    sort01(arr,8);
    printarr(arr,8);

}