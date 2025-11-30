/*
You are given an array 'ARR' of integers having 'N' elements. Your task is to convert the input array into a min-Binary Heap.

A min-Binary heap is a complete binary tree in which the value of each internal node is smaller than or equal to the values of the children of that node.

Note :
1. Input array follows 0 - based indexing. 

2. After constructing the min-heap, the Left child of the 'i-th' node should be present at the (2*i + 1)-th index if it exists.

3. After constructing the min-heap, the Right child of the 'i-th' node should be present at the (2*i + 2)-th index if it exists.

4. Note that you do not need to create a tree, just update the array.
*/

#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr,int n,int index){
    int smallest=index;

    while(true){
        int left=2*index +1;
        int right = 2*index +2;

        if(left<n && arr[left] < arr[smallest]){
            smallest =left;
        }
        if(right < n && arr[right]< arr[smallest ]){
            smallest =right ;
        }

        if(smallest != index){
            swap(arr[smallest],arr[index]);
            index=smallest;
        }else{
            return;
        }
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    int n=arr.size();

    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }

    return arr;
}
