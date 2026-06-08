class Solution 
{
    public:
    int minMeetingRooms(vector<vector<int>>& intervals) 
    {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        // minHeap with endTimes
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i=0; i<n; i++) {
            // check to see if there's any room can be released
            if (!pq.empty() && pq.top() <= intervals[i][0]) {
                pq.pop();
            } 
            pq.push(intervals[i][1]);
        }
        return pq.size();
    }
};