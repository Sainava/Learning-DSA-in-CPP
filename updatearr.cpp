#include<iostream>
using namespace std;

void update(int arr[],int size){

    arr[0]=120;

    cout << "Inside the update function" << endl;
    for (int i=0;i<size;i++){
            cout << arr[i] << " ";
        }
}




int main(){
        int arr[100];
        cout << "Enter the size" << " ";
        int size;
        cin >> size;

        for (int i=0;i<size;i++){
            cin >> arr[i];
        }
         
        update(arr,size);

        cout << "After updation" << endl;
         
        for (int i=0;i<size;i++){
            cout << arr[i] << " ";
        }
}