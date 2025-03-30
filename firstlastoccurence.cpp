#include<iostream>
using namespace std;

int firstOcc(int arr[],int n,int key){

    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    int ans=-1;

    while(s<=e){
        if (arr[mid]==key){
                ans=mid;
                e=mid-1;
        }

        else if (arr[mid]>key){
            e=mid-1;
        }

        else {
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }


    return ans;

}

int lastOcc(int arr[],int n,int key){

    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    int ans=-1;

    while(s<=e){
        if (arr[mid]==key){
                ans=mid;
                s=mid+1;
        }

        else if (arr[mid]>key){
            e=mid-1;
        }

        else {
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }

    return ans;

}

int main(){
    int arr[11]={1,2,3,4,4,4,4,4,5,6,7};
    
    cout << " The first occurence of 4 is at index: " <<firstOcc(arr,11,4)<< endl;
    cout << " The last occurence of 4 is at index: " <<lastOcc(arr,11,4)<< endl;
    cout << "The total number of occurences of 4 is : "<< (lastOcc(arr,11,4) - firstOcc(arr,11,4) )+  1;
}