

// Time: O(N logN)
// Space: O(N)

class Solution 
{
    public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        if (position.empty() || speed.empty()) return 0;
        int n = position.size();

        // bundle pos and spd, sort in descending in pos
        vector<pair<int, int>> cars;
        for (int i=0; i<n; i++) {
            cars.push_back( {position[i], speed[i]} );
        }

        // sort the bundle 
        sort(cars.rbegin(), cars.rend());
        stack<double> deck;

        // look back from the right end
        for (auto& [pos, spd] : cars) { 
            // compute the time
            double time = (double)(target-pos) / spd;
            // if the time is larger than the one on top
            // then means this car can never catch the car ahead, 
            // fleet++
            if (deck.empty() || time > deck.top()) {
                deck.push(time);
            }
        }
        return deck.size();
    }
};