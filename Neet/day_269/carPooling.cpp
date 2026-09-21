class Solution 
{
    public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        if (trips.empty()) return {};

        // sort the trips based on startTime trip[1]
        sort(trips.begin(), trips.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });

        // pq to earlier endtime on top, { endTime, numPassengers }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        int currCap = capacity;
        for (auto& trip : trips) {
            int numPassengers = trip[0];
            int start = trip[1];
            int end = trip[2];

            // gain all capacity back
            while (!pq.empty() && pq.top().first <= start) {
                currCap += pq.top().second;
                pq.pop();
            }

            if (currCap - numPassengers < 0) return false;
            currCap -= numPassengers;
            pq.push( {end, numPassengers} ); 
        }
        return true;
    }
};