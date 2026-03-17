


// Time: O(N log N), dominated by sorting
// Space: O(N)
class Solution 
{
    public:
    int minMeetingRooms(vector<vector<int>>& intervals) 
    {
        if (intervals.empty()) return 0;
        int n = intervals.size();

        // sort by the start of each of the intervals
        sort(intervals.begin(), intervals.end());

        // minHeap, containing the endTimes
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i=0; i<n; i++) {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            if (!pq.empty() && pq.top() <= currStart) {
                pq.pop(); // rooms can be released
            }
            pq.push(currEnd);
        }
        return pq.size();
    }
};