#include<iostream>
#include<algorithm>
using namespace std;

void bubbleSort(int arr[],int n) {

    
    for (int i = 0; i < n - 1; i++) {

        // Last i elements are already
        // in place
        for (int j = 0; j < n - i - 1; j++) {
          
              // Comparing adjacent elements
            if (arr[j] > arr[j + 1])
              
                  // Swapping if in the wrong order
                swap(arr[j], arr[j + 1]);
        }
    }
}



bool ispossible(int arr[],int n,int k,int mid){
    int cowCount=1;
    int lastpos=arr[0];

    for(int i=0;i<n;i++){

        if(arr[i]-lastpos>=mid){
            cowCount++;
            if(cowCount==k){
                return true;
            }
            lastpos=arr[i];
        }
    }
    return false;
}

int aggresive(int arr[],int n,int k){

    bubbleSort(arr,n);

    int s=0;
    int maxi=-1;

    for(int i=0;i<n;i++){
        maxi=max(maxi,arr[i]);
    }   
    int e=maxi;
    int mid=s +(e-s)/2;
    int ans=-1;
   /* cout << "e through maxi : " << e << endl;;
    cout << "e through last element : " << arr[n-1];*/

    while(s<=e){
        if (ispossible(arr,n,k,mid)){
               ans =mid;
                s=mid+1;
        }

        else{
            e=mid-1;
        }
        mid=s +(e-s)/2;
    }
    return ans;

}

int main(){
    int arr[5]= {4,2,1,3,6};
    cout<< "The required answer is : " << aggresive(arr,5,2);
}