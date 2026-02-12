class Solution 
{
    public:
    int minMeetingRooms(vector<vector<int>>& intervals) 
    {
        if (intervals.empty()) return 0;
        int n = intervals.size();

        // sort based on startTime
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });

        priority_queue<int, vector<int>, greater<int>> pq; // earlier endTimes on top

        for (int i=0; i<n; i++) {
            if (!pq.empty() && intervals[i][0] >= pq.top()) {
                pq.pop();
            }

            pq.push(intervals[i][1]);
        }
        return pq.size();
    }
};