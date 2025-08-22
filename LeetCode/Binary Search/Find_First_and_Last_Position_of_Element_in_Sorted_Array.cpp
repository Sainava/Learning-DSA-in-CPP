/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
*/

#include<iostream>
#include<vector>
using namespace std;

//Solution 1
class Solution1 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=-1;
        int last=-1;

        int start=0;
        int end=nums.size()-1;
        
        while(start<=end){
            int mid = start+ (end-start)/2;

            if(nums[mid]==target ){
                first=mid;
                end=mid-1;
                continue;
            }

            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }

        start=0;
        end=nums.size()-1;

        while(start<=end){
            int mid = start+ (end-start)/2;

            if(nums[mid]==target ){
                last=mid;
                start=mid+1;
                continue;
            }

            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        
        //TC:O(logn)
        //SC:O(1)
        return {first,last};
        
    }
};


//Solution 2
class Solution2 {
public:

    int helper(vector<int>& nums, int target,bool firstFind){
        int index=-1;
        int start=0;
        int end=nums.size()-1;
        
        while(start<=end){
            int mid = start+ (end-start)/2;

            if(nums[mid]==target ){
                index=mid;

                if(firstFind){
                    end=mid-1;
                }else{
                    start=mid+1;
                }
                
                continue;
            }

            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }

        return index;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first=helper(nums,target,true);
        int last=helper(nums,target,false);



        //TC:O(logn)
        //SC:O(1)
        return {first,last};
        
    }
};