

// Time: O(N logN)
// Space: O(N)

class Solution 
{
    public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        if (position.empty() || speed.empty()) return 0;

        int n = position.size();
        vector<pair<int, int>> cars;
        for (int i=0; i<n; i++) {
            cars.push_back( {position[i], speed[i]} );
        }

        // sort by descending order of pos
        sort(cars.rbegin(), cars.rend());
        stack<double> deck; // store time reaching target

        for (int i=0; i<n; i++) {
            // time reaching target for this car
            int pos = cars[i].first;
            int spd = cars[i].second;
            double time = (double)(target - pos) / spd;
            
            if (deck.empty() || time > deck.top()) {
                deck.push(time);
            }
        }
        return deck.size();
    }
};