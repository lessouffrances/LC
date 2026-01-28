class Solution 
{
    public:
    int minMeetingRooms(vector<vector<int>>& intervals)
    {
        if (intervals.empty()) return 0;
        int n = intervals.size();

        // sort the intervals based on starTime
        sort(intervals.begin(), intervals.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i=0; i<n; i++) {
            int startTime = intervals[i][0];
            if (!pq.empty() && pq.top() <= startTime) {
                pq.pop();
            }

            pq.push(intervals[i][1]);
        }
        return pq.size();
    }
};