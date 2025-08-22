/*
(This problem is an interactive problem.)

You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. If such an index does not exist, return -1.

You cannot access the mountain array directly. You may only access the array using a MountainArray interface:

MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.
Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.
*/

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

 #include <iostream>
 #include <vector>
 #include <algorithm>
 using namespace std;

 // This is the MountainArray's API interface.
 // You should not implement it, or speculate about its implementation
 class MountainArray {
   public:
     int get(int index);
     int length();
 };

class Solution {
public:
    int findPeak(MountainArray &mountainArr,int n){
        int start=0;
        int end=n-1;

        while(start<end){
            int mid= start + (end - start)/2; 
            int midElement=mountainArr.get(mid);
            int nextElement=mountainArr.get(mid+1);

            if(midElement <  nextElement){
                start=mid+1;
            }
            else{
                end=mid;
            }
        }
        return start; 
    }

    int binarySearch(int target, MountainArray &mountainArr,int start,int end,bool isAscending){
        while(start<=end){
            int mid=start+(end-start)/2;
            int midElement=mountainArr.get(mid);

            if(midElement==target){
                return mid;
            }

            if (isAscending){
                if(midElement < target){
                    start=mid+1;
                }else{
                    end=mid-1;
                }
            }
            else{
                
                if(midElement > target){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
                
            }
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();

        int peakElement=findPeak(mountainArr,n);
        int index=binarySearch(target, mountainArr,0,peakElement,true);
        if(index!=-1){
            return index;
        }
        index=binarySearch(target,mountainArr,peakElement+1,n-1,false);
        return index;

        //TC:O(logn)
        //SC:O(1)
    }

};