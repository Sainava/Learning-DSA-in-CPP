/*
You are given an array of integers a and an
integer k. Your task is to calculate the number
of ways to pick two different indices i < j, such
that a[i] + a[j] is divisible by k.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // Create the remainder frequency map
        unordered_map<int,int> count;

        for(int num:nums){
            int rem=num%k;
            if(rem<0){
                rem+=k;
            }
            count[rem]++;
        }

        int ans=0;

        //Zero pairs with themselves
        int cnt=count[0];
        ans+=cnt*(cnt-1)/2;

        // pairs of r and k-r
        for(int r=1;r*2<k;r++){
            int cnt1=count[r];
            int cnt2=count[k-r];
            ans+=cnt1*cnt2;
        }

        //if k is divisible by 2 , k/2 pairs with itself
        if(k%2==0){
            int cnt=count[k/2];
            ans+=cnt*(cnt-1)/2;
        }

        return ans;
        
        
    }
};