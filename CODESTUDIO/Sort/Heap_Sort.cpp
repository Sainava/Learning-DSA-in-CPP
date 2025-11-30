/*
Problem statement
You are given an array ‘ARR’ consisting of 'N' integers, and your task is to sort the given array in non-decreasing order using the Heap sort algorithm.
*/

#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n,int index){
	int largest=index;
	while(true){


		int left=2*index+1;
		int right = 2*index +2 ;

		if(left<n && arr[left]> arr[largest]){
			largest=left;
		}		
		if(right<n && arr[right]> arr[largest]){
			largest=right;
		}


		if(index!=largest){
			swap(arr[largest],arr[index]);
			index=largest;
		}
		else{
			return;
		}
	}
}

vector<int> heapSort(vector<int>& arr, int n) {	
	//heapify 
	for(int i=n/2 -1 ;i>=0;i--){
		heapify(arr,n,i);
	}

	int size=n;

	while(size>1){
		swap(arr[0],arr[size-1]);
		
		size--;

		heapify(arr,size,0);
	}

	return arr;
	//TC:O(nlogn) and SC:O(1)
	
}