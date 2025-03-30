#include<iostream>
#include<algorithm>
using namespace std;

void printarr(char arr[],int size){
              for(int i=0;i<size;i++){
                    cout << arr[i] << " ";
    }
}


int main(){

    int arr[15] ;
    fill(arr,arr+15,10);
   
    // int arrsize=sizeof(arr)/sizeof(int);
    // cout << "Size is " << arrsize;
    char ch[5]={'a','b','c'};
     printarr(ch,5);
  
}