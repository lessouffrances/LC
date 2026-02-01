class Solution 
{
    public:
    int minMeetingRooms(vector<vector<int>>& intervals) 
    {
        if (intervals.empty()) return 0;

        // sort intervals based on startTime
        sort(intervals.begin(), intervals.end());
        // earlier endTime on top
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto& inter : intervals) {
            // check for release
            if (!pq.empty() && pq.top() <= inter[0]) {
                pq.pop();
            }

            pq.push(inter[1]);
        }
        
        return pq.size();
    }
};