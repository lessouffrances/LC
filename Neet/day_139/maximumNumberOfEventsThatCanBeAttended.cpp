

// Time: O(N logN) considering each op in heap is logN
// Space: O(N)
class Solution 
{
    public:
    int maxEvents(vector<vector<int>>& events) 
    {
        if (events.empty()) return 0;
        int n = events.size();

        // sort events based on startTime
        sort(events.begin(), events.end());

        // minHeap to store endTimes of active events
        priority_queue<int, vector<int>, greater<int>> pq;
        int numOfEventsCanAttend = 0;
        int eventIdx = 0;
        int day = 1;

        while (eventIdx < n || !pq.empty()) {
            // if no active events, time jumps to the startTime for the next event
            if (pq.empty()) {
                day = events[eventIdx][0];
            }

            // push the endTimes of all events start before and today
            while (eventIdx < n && events[eventIdx][0] <= day) {
                pq.push(events[eventIdx][1]);
                eventIdx++;
            }

            // clear expired events on pq
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }

            // what's left on pq are valid events we can attend today
            // but for once, since we cannot attend multiple events per day
            if (!pq.empty()) {
                pq.pop();
                numOfEventsCanAttend++;
            }
            day++;
        }
        return numOfEventsCanAttend;
    }
};