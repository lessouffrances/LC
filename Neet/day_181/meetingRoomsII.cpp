


class Solution 
{
    public:
    int minMeetingRooms(vector<vector<int>>& intervals) 
    {
        if (intervals.empty()) {
            return 0;
        }

        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        // minHeap containing the end times
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[0][1]);

        for (int i=1; i<n; i++) {
            // check if rooms can be released
            int earliestEndTime = pq.top();
            if (earliestEndTime <= intervals[i][0]) {
                pq.pop();
            } 
            pq.push(intervals[i][1]);

        }
        return pq.size();
    }
};