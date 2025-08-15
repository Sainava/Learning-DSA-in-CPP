/*
Given an array nums of integers, return how many of them contain an even number of digits.
*/
#include<iostream>
using namespace std;

class Solution1 {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            int number=nums[i];
            int digit=0;
            while(number>0){
                number=number/10;
                digit++;
            }

            if(digit%2==0){
                count++;
            }
        }

        //TC: O(n.d) where d is the length of largest numeber
        //SC:O(1)
        return count;
    }
};


//More Optimised
class Solution2 {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            int number=nums[i];

            if (number==0) continue ; // as log 0 is undefined

            int digits=floor(log10(number)+1);

            if(digits % 2==0){
                count++;
            }
        }

        //TC: O(n) where n is the size of numbers 
        //SC:O(1)
        return count;
    }
};