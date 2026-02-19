class Solution 
{
    public:
    int minMeetingRooms(vector<vector<int>>& intervals) 
    {
        if (intervals.empty()) return 0;
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[0] < b[0];
        });

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i=0; i<n; i++) {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];
            // check if rooms can be released
            if (!pq.empty() && pq.top() <= currStart) {
                pq.pop();
            }
            pq.push(currEnd);
        }
        return pq.size();
    }
};