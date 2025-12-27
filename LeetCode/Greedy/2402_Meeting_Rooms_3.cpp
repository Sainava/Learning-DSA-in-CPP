/*
You are given an integer n. There are n rooms numbered from 0 to n - 1.

You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during the half-closed time interval [starti, endi). All the values of starti are unique.

Meetings are allocated to rooms in the following manner:

Each meeting will take place in the unused room with the lowest number.
If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting.
When a room becomes unused, meetings that have an earlier original start time should be given the room.
Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

A half-closed interval [a, b) is the interval between a and b including a and not including b.

 

Example 1:

Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
Output: 0
Explanation:
- At time 0, both rooms are not being used. The first meeting starts in room 0.
- At time 1, only room 1 is not being used. The second meeting starts in room 1.
- At time 2, both rooms are being used. The third meeting is delayed.
- At time 3, both rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 1 finishes. The third meeting starts in room 1 for the time period [5,10).
- At time 10, the meetings in both rooms finish. The fourth meeting starts in room 0 for the time period [10,11).
Both rooms 0 and 1 held 2 meetings, so we return 0. 
Example 2:

Input: n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
Output: 1
Explanation:
- At time 1, all three rooms are not being used. The first meeting starts in room 0.
- At time 2, rooms 1 and 2 are not being used. The second meeting starts in room 1.
- At time 3, only room 2 is not being used. The third meeting starts in room 2.
- At time 4, all three rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 2 finishes. The fourth meeting starts in room 2 for the time period [5,10).
- At time 6, all three rooms are being used. The fifth meeting is delayed.
- At time 10, the meetings in rooms 1 and 2 finish. The fifth meeting starts in room 1 for the time period [10,12).
Room 0 held 1 meeting while rooms 1 and 2 each held 2 meetings, so we return 1. 
 

Constraints:

1 <= n <= 100
1 <= meetings.length <= 105
meetings[i].length == 2
0 <= starti < endi <= 5 * 105
All the values of starti are unique.
*/

#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        //TC:O(mlogm)
        // Sort the meetings based on start time 
        sort(meetings.begin() , meetings.end());

        // Two min heaps  -- Free Rooms and Busy Rooms 

        //Free Room ( so we choose the smallest room number each time )
        //SC:O(n) --> max
        priority_queue<int,vector<int>,greater<int>> freeRooms;

        for(int i =0 ; i < n ; i++){
            freeRooms.push(i);
        }

        // BusyRooms - Sorted by end time and then by room number {end time , room number}
        //SC:O(n) --> max
        priority_queue<
            pair< long long , int >,
            vector< pair <long long,int>> ,
            greater< pair<long long,int>>
        > busyRooms ; 

        // Count the number of meetings in each room 
        //SC:O(n)
        vector<int> count(n) ;


        // Process each meeting 
        //TC:O(m)
        for ( auto &m : meetings){

            long long startTime = m[0];
            long long endTime = m[1];
            long long duration = endTime -startTime ;

            // First free the rooms that have completed the meeting 
            
            //Each meeting is pushed and poped once into the heaps , and each push and pop is logn as n rooms max for heaps so TC:O(mlogn)
            while( !busyRooms.empty() && busyRooms.top().first <= startTime ) {
                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            //Similarly O(mlogn)

            // When a room is free 
            if(!freeRooms.empty()){
                int room = freeRooms.top();
                freeRooms.pop();

                count[room]++;
                busyRooms.push({endTime,room});

            }
            //Otherwise delay the meeting 
            else{
                auto [finishTime, room ]= busyRooms.top();
                busyRooms.pop();

                count[room]++;
                busyRooms.push({finishTime + duration , room });
            }
        }

        // Find the room with the highest Count ;
        int maxRoom = 0;

        //SC::(n)
        for( int i=0 ; i < n ;i++){
            if(count[i] > count[maxRoom]){
                maxRoom = i;
            }
        }

        //TC:O( mlogm + mlogn) --> Here m >> n so simplifies to  TC:O(mlogm)
        //SC:O(n)
        return maxRoom;



    }
};