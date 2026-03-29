





// Time: O(N logN)
// Space: O(1)

// temperatures = [73,74,75,71,69,72,76,73]
class Solution 
{
    public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        if (temperatures.empty()) return {};
        int n = temperatures.size();

        stack<pair<int, int>> deck; // {temp, idx}
        vector<int> res(n, 0);

        for (int i=0; i<n; i++) {
            while (!deck.empty() && deck.top().first < temperatures[i]) {
                auto [temp, idx] = deck.top();
                res[idx] = i-idx;
                deck.pop();
            }

            deck.push( {temperatures[i], i} );
        }
        return res;
    }
};