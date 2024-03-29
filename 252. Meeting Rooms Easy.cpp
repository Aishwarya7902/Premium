/*
0 - 6 months
Palo Alto Networks
2
6 months - 1 year
Google
2
eBay
2
Apple
2
1 year - 2 years
Amazon
4
Bloomberg
2
Oracle
2
Facebook
*/

Given an array of meeting time intervals where intervals[i] = [starti, endi],
determine if a person could attend all meetings.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: false
Example 2:

Input: intervals = [[7,10],[2,4]]
Output: true
 

Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti < endi <= 106



 ********************************************* SOLUTION ************************************************************************

 //TC: O(nlogn)
 //SC : O(1)

 class Solution {
public:
    static bool comp(vector<int> &vec1,vector<int> &vec2){
      return  vec1[0]<vec2[0];
    }
   

    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(begin(intervals),end(intervals),comp);
       
        for(int i=1;i<n;i++){
            if(intervals[i][0]<intervals[i-1][1])return false;
        }
        return true;
    }
};
