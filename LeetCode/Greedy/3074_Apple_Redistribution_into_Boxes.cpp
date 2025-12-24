/*
You are given an array apple of size n and an array capacity of size m.

There are n packs where the ith pack contains apple[i] apples. There are m boxes as well, and the ith box has a capacity of capacity[i] apples.

Return the minimum number of boxes you need to select to redistribute these n packs of apples into boxes.

Note that, apples from the same pack can be distributed into different boxes.

 

Example 1:

Input: apple = [1,3,2], capacity = [4,3,1,5,2]
Output: 2
Explanation: We will use boxes with capacities 4 and 5.
It is possible to distribute the apples as the total capacity is greater than or equal to the total number of apples.
Example 2:

Input: apple = [5,5,5], capacity = [2,4,2,7]
Output: 4
Explanation: We will need to use all the boxes.
 

Constraints:

1 <= n == apple.length <= 50
1 <= m == capacity.length <= 50
1 <= apple[i], capacity[i] <= 50
The input is generated such that it's possible to redistribute packs of apples into boxes.
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples= 0 ;

        //TC:O(n)
        for (int &a:apple){
            totalApples+=a;
        }

        //TC:O(mlogm)
        //sort() in C++ does not guarantee O(1) memory
        // It uses introsort, which takes:
        // O(log m) stack space (recursion)
        
        sort(capacity.begin(),capacity.end(),greater<int>());

        int m = capacity.size();

        int usedCapacity = 0;

        //TC:O(m)
        for(int i=0;i<m ;i++){

          usedCapacity += capacity[i];

            if(usedCapacity >= totalApples){
                return i+1;
            }
           
        }

        //TC:O(n+mlogm)
        // SC: O(log m) due to sorting (O(1) extra space)
        return -1;

    }
};