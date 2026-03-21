


class Solution 
{
    public:
    int maxEvents(vector<vector<int>>& events) 
    {
        if (events.empty()) return 0;
        int n = events.size();
        // sort based on startTimes;
        sort(events.begin(), events.end());

        // minHeap to store endTimes for active events
        priority_queue<int, vector<int>, greater<int>> pq;

        int numOfEventsCanBeAttended = 0;
        int today = 1;
        int eventIdx = 0;
        while (eventIdx < n || !pq.empty()) {
            // if no active events now, 
            // jump to the next event 
            if (pq.empty()) {
                today = events[eventIdx][0];
            }

            // push the endTimes for all events that start <= today
            while (eventIdx < n && events[eventIdx][0] <= today) {
                pq.push(events[eventIdx][1]);
                eventIdx++;
            }

            // clear expired events on pq
            while (!pq.empty() && pq.top() < today) {
                pq.pop();
            }

            // what's left are the events can be attended for today,
            // but we can only attend one event per day
            if (!pq.empty()) {
                numOfEventsCanBeAttended++;
                pq.pop();
            }
            
            // increment time
            today++;
        }
        
        return numOfEventsCanBeAttended;
    }
};