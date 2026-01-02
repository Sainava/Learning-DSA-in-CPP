/*
You are given an integer array nums with the following properties:

nums.length == 2 * n.
nums contains n + 1 unique elements.
Exactly one element of nums is repeated n times.
Return the element that is repeated n times.

 

Example 1:

Input: nums = [1,2,3,3]
Output: 3
Example 2:

Input: nums = [2,1,2,5,3,2]
Output: 2
Example 3:

Input: nums = [5,1,5,2,5,3,5,4]
Output: 5
 

Constraints:

2 <= n <= 5000
nums.length == 2 * n
0 <= nums[i] <= 104
nums contains n + 1 unique elements and one of them is repeated exactly n times.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int size = nums.size();

        // This covers minimum size of 4 , where n=2 (so n*2 = 2*2 = 4 size)
        for(int i = 0 ; i <= size-3 ; i++){
            if(nums[i] == nums[i+1] || nums[i]==nums[i+2]){
                return nums[i];
            }
        }

        // When n=1 so size = 2*1 = 2 , both elements are same 
        // Or since the above loop never compares the last two elements directly , (test case 1 ) 
        return nums[size - 1];

        //TC:O(n)
        //SC:(1)
    }
};