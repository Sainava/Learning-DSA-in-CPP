#include<iostream>
#include<limits.h>
using namespace std;

int getmax(int arr[],int n){
    int maxi=INT_MIN;

    for(int i=0;i<n;i++){
    //Method 1
    //     if(arr[i]>maxi){
    //         maxi=arr[i];
    //     }
    // }

    //Method 2
    maxi=max(maxi,arr[i]);
    }
    return maxi;

}

int getmin(int arr[],int n){

     int mini=INT_MAX;

    for(int i=0;i<n;i++){
    //Method 1
    //     if(arr[i]<mini){
    //         mini=arr[i];
    //     }
    // }

    //Method 2
    mini=min(mini,arr[i]);
    }
    return mini;
}



int main(){

    int size;
    cout << " Enter the size :" << " " ;
    cin >> size;

    int arr[100];
    for (int i=0;i<size;i++){
        cin >> arr[i];
    }

    // for (int i=0;i<100;i++){
    //     cout << arr[i]<< " ";
    // }

    cout << "The Maximum element is " << " " << getmax(arr,size) << endl;

    cout << "The Minimum element is " << " " << getmin(arr,size) << endl;


}