class Solution 
{
    public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        if (position.empty() || speed.empty()) return 0;
        int n = position.size();

        // bundle the speed and the position
        vector<pair<int, int>> cars;
        for (int i=0; i<n; i++) {
            cars.push_back( {position[i], speed[i]} );
        }

        // sort based on the descending pos
        sort(cars.rbegin(), cars.rend());

        // naturally contains the time to reach target for the fleet ahead
        stack<double> deck; 

        for (auto& [pos, spd] : cars) {
            // the time for this car to reach target
            double time = (double)(target-pos) / spd;

            // this car takes longer time to reach target;
            // can never catch with the car ahead, so fleet ++
            if (deck.empty() || time > deck.top()) {
                deck.push(time);
            }
        }
        return deck.size();
    }
};