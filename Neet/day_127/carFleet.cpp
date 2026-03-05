class Solution 
{
    public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        int n = position.size();
        vector<pair<int, int>> cars;
        
        for (int i=0; i<n; i++) {
            cars.push_back( {position[i], speed[i]} );
        }

        // sort them based on positions, descending
        sort(cars.rbegin(), cars.rend());

        // stack contains the time to reach target for the fleet ahead
        stack<double> deck;
        for (auto& [pos, speed] : cars) {
            double time = (double)(target-pos) / speed;

            // if this car takes longer than the car ahead to reach the target
            // means that it can catch up
            if (deck.empty() || time > deck.top()) deck.push(time);
        }
        return deck.size();
    }
};