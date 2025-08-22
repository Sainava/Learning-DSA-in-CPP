/*
You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

Return the index of the peak element.

Your task is to solve it in O(log(n)) time complexity.
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start=0 ;
        int end=arr.size() -1 ;

        int mid=start + (end-start)/2;

        while(start<end){
            if(arr[mid]<arr[mid+1]){
                start=mid+1;
            }
            else{
                end=mid;
            }

            mid=start+(end-start)/2;
        }

        //TC:O(logn)
        //SC:O(1)
        return start;
    }

    
};

/*
The transition from s <= e to s < e and the change from end = mid - 1 to end = mid is a subtle but crucial part of mastering binary search for problems like this.

The key is to understand the search space and the invariant you're trying to maintain.

The Search Space
In a typical binary search where you're just finding a single element, the search space can become empty. That's why you use start <= end. However, for a peak-finding problem, the peak must exist within the array. Your search space, therefore, never becomes empty. start and end will eventually converge to the single index of the peak.

The Invariants
Let's break down the logic with respect to the peak:

if (arr[mid] < arr[mid+1]): This condition tells you that you are on the uphill slope of the mountain. The peak must be somewhere to your right. So, you can safely discard the current mid and everything to its left. The new search space starts at mid + 1. This is why start = mid + 1.

else (where arr[mid] > arr[mid+1]): This condition means you are either at the peak itself or on the downhill slope. The peak could be at mid or somewhere to its left. You can't discard mid because it could be the answer. Therefore, you update your search space to end = mid.

Why s < e and end = mid?
The combination of start < end and end = mid is what makes this binary search variant work correctly for finding a peak.

If you used end = mid - 1, you might mistakenly discard the peak itself. For example, if mid is the peak, and you move end to mid-1, you've just thrown away the answer.

The loop terminates when start == end. At this point, the search space has converged to a single element. Because of the logic used in the loop, this single element must be the peak.

Essentially, this is a specialized form of binary search. You aren't searching for a specific value; you are searching for the position that satisfies a certain condition (being greater than its neighbors). The adjustments to the loop conditions and start/end updates are tailored specifically to the mountain array problem to ensure the search space always contains the peak.




The "No Empty Search Space" Principle
You're right: in this specific problem, a peak is guaranteed to exist. This means the search space will never become empty. The loop while (start < end) is designed to run until start and end converge to the single index of the peak, at which point the loop terminates, and start (or end) holds the correct answer. This saves you one iteration compared to start <= end where you'd have to check for equality inside the loop.

Analyzing the Search Conditions
if (arr[mid] < arr[mid + 1]): This condition confirms you are on an increasing slope. You know for sure that the peak is to the right of mid, so you can safely discard mid and everything to its left. Setting start = mid + 1 is correct and efficient.

else (where arr[mid] >= arr[mid + 1]): This is the crucial part. This means you are either at the peak or on a decreasing slope. The peak could be at mid itself or somewhere to its left. You cannot discard mid because it could be the correct answer. Therefore, you must keep it in your search space by setting end = mid. This is the mechanism that ensures the correct answer is never lost.

*/