
// pq, contains pairs of {end, numOfPassengers}, min end on top
// trips have to be sorted based on start time
// simulate the process, if at any point in time the totalPassengers > capacity, return false

class Solution 
{
    public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        // sort trips based on start time
        sort(trips.begin(), trips.end(), [](const auto& a, const auto& b){
            return a[1] < b[1]; 
        });

        // minHeap, { endTime, numOfPassengers }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // init 
        int currCapacity = capacity;

        for (auto& trip : trips) {
            // unpack values
            int numPassengers = trip[0];
            int from = trip[1];
            int to = trip[2];

            // when arrive at this point, the first thing to do is to release passengers
            while (!pq.empty() && pq.top().first <= from) {
                // gain capacity back
                currCapacity += pq.top().second;
                pq.pop();
            }

            // cannot do this trip, so all fail
            if (currCapacity - numPassengers < 0) return false;

            currCapacity -= numPassengers;
            pq.push( {to, numPassengers} );
        }
        return true;
    }
};