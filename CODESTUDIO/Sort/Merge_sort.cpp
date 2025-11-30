/*
Problem statement
You are given the starting 'l' and the ending 'r' positions of the array 'ARR'.



You must sort the elements between 'l' and 'r'.



Note:
Change in the input array itself. So no need to return or print anything.
Example:
Input: ‘N’ = 7,
'ARR' = [2, 13, 4, 1, 3, 6, 28]

Output: [1 2 3 4 6 13 28]
*/

#include <iostream>
using namespace std;


void merge(int *arr, int l, int r){
    int mid=l+(r-l)/2;

    int len1=mid-l+1;
    int len2=r-mid;


    int *first=new int[len1];
    int *second=new int[len2];

    int k=l;

    for(int i=0;i<len1;i++){
        first[i]=arr[k++];
    }

    k=mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[k++];
    }

    int index1=0;
    int index2=0;

    while(index1 < len1 && index2< len2){
        if(first[index1]<second[index2]){
            arr[l++]=first[index1++];
        }
        else {
            arr[l++]=second[index2++];
        }
    }

    while(index1<len1){
        arr[l++]=first[index1++];
    }

    while(index2<len2){
        arr[l++]=second[index2++];
    }

    delete [] first;
    delete [] second;
    
}


void mergeSort(int arr[], int l, int r) {
   if(l>=r){
       return ;
   }

   int mid=l+(r-l)/2;

   mergeSort(arr,l,mid);
   mergeSort(arr,mid+1,r);

   merge(arr,l,r);

   //TC:O(nlogn)
}

