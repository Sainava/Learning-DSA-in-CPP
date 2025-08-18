/*
You are given a sorted array A consisting of N integers. Your task is to find the magic index in the given array.

Note :
1. A magic index in an array A[0 ... N - 1] is defined to be an index i such that A[i] = i.
2. The elements in the array can be negative.
3. The elements in the array can be repeated multiple times.
4. There can be more than one magic index in an array.
*/


#include <iostream>
#include <vector>
using namespace std;
int magicIndex(vector<int> a, int n) {
	// Write your code here
	for(int i=0;i<n;i++){
		if(a[i]==i){
			return i;
		}
	}
	//TC:O(n)
	//sc:O(1)
	return -1;
}

// Since this has duplicate elements , we cannot use binary search so the complexity cannot be brought down to O(logn)