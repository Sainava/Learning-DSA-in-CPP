#include<iostream>
using namespace std;

void alternate(int arr[],int size){
    int temp;
    for(int i=0;i<size;i+=2){
        if(i+1<size){
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }
}


void printarr(int arr[],int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(){

    int even[8]={5,2,9,4,7,6,1,0};
    int odd[5]={11,33,9,76,43};

    alternate(even,8);
    alternate(odd,5);

    printarr(even,8);
    printarr(odd,5);
}