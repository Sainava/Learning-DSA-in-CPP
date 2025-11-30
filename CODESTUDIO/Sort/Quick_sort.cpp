/*
Problem statement
You are given an array of integers. You need to sort the array in ascending order using quick sort.

Quick sort is a divide and conquer algorithm in which we choose a pivot point and partition the array into two parts i.e, left and right. The left part contains the numbers smaller than the pivot element and the right part contains the numbers larger than the pivot element. Then we recursively sort the left and right parts of the array.

Example:

Let the array = [ 4, 2, 1, 5, 3 ]
Let pivot to be the rightmost number.
*/

#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr,int s,int e){
    int pivot=s;
    int pivotElement=arr[s];

    int count=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<pivotElement){
            count++;
        }
    }

    pivot=pivot+count;
    swap(arr[s],arr[pivot]);

    int i=s;
    int j=e;

    while(i<pivot && j>pivot){
        while(i < pivot && arr[i] < pivotElement){
            i++;
        }
        while(j > pivot && arr[j] > pivotElement){
            j--;
        }

        if(i<pivot && j>pivot){
            swap(arr[i++],arr[j--]);
        }

    }

    return pivot;
}

void solve(vector<int> &arr,int s,int e){
    if(s>=e){
        return;
    }

    int p=partition(arr,s,e);
    solve(arr,s,p-1);
    solve(arr,p+1,e);
}

vector<int> quickSort(vector<int> arr)
{
    solve(arr,0,arr.size()-1);
    return arr;
}
