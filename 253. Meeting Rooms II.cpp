/*
  0 - 6 months
Facebook
13
IBM
10
Bloomberg
8
Google
7
TikTok
7
Microsoft
4
Amazon
4
Oracle
3
Pinterest
2
Yandex
2
6 months - 1 year
Apple
3
Snapchat
2
Salesforce
2
Goldman Sachs
2
Miro
2
1 year - 2 years
Uber
7
eBay
5
Walmart Labs
4
PayPal
3
Visa
3
ByteDance
3
Cruise Automation
2
Splunk
2
ServiceNow
2
Workday
2
  */


Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2
Example 2:

Input: intervals = [[7,10],[2,4]]
Output: 1
 

Constraints:

1 <= intervals.length <= 104
0 <= starti < endi <= 106



  ********************************************************  SOLUTION ***************************************************
//TC : O(nlogn)
//SC : O(n)
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int>start;
        vector<int>endTime;
        int n=intervals.size();
        for(auto it:intervals){
            start.push_back(it[0]);
            endTime.push_back(it[1]);
        }

        sort(begin(start),end(start));
        sort(begin(endTime),end(endTime));

        int res=0,count=0;

        int s=0,e=0;

        while(s<n){

            if(start[s]<endTime[e]){ //start a new meet
                count++;
                s++;
            }
            else{ //end a meet
                e++;
                count--;
            }

            res=max(res,count);
        }

        return res;
    }
};
