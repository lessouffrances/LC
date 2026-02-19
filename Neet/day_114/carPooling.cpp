




class Solution 
{
    public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        if (trips.empty()) return true;
        // sort based on startTime
        sort(trips.begin(), trips.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });
        // checking if we released the passengers from last trip
        auto comp = [](const auto & a, const auto& b) {
            return a.first > b.first; // earlier end on top
        };
        // pair: { end, numOfPassengers }
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq{comp};

        // [[3,2,8],[4,4,6],[10,8,9]]
        // pq {3,8},{6,4}
        // cap 4
        for (auto& t : trips) {
            int numOfPassengers = t[0]; 
            int start = t[1];
            int end = t[2];

            // check to release passengers from last trip;
            while (!pq.empty() && pq.top().first <= start) {
                capacity += pq.top().second;
                pq.pop();
            }

            // check to see if we can take on this trip
            if (capacity < numOfPassengers) return false; // early-return

            capacity -= numOfPassengers;
            pq.push( {end, numOfPassengers} );
        }
        return true;
    }
};