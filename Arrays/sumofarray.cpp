#include<iostream>
using namespace std;

int sum(int arr[],int size){

    int sum=0;
    for (int i=0;i<size;i++){
            sum+=arr[i];
        }
        return sum;
}




int main(){
        int arr[100];
        cout << "Enter the size" << " ";
        int size;
        cin >> size;

        for (int i=0;i<size;i++){
            cin >> arr[i];
        }
         
        cout << "The sum of elements of the array is:" << sum(arr,size)<< endl;

      
}