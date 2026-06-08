

// temperatures = [73,74,75,71,69,72,76,73]
//                 [1,1,4,2,1,1,0,0]
// stack = [75]
class Solution 
{
    public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        if (temperatures.empty()) return {};

        stack<pair<int, int>> deck; // { temp, idx }
        int n = temperatures.size();
        vector<int> res(n, 0);

        for (int i=0; i<n; i++) {
            while (!deck.empty() && temperatures[i] > deck.top().first) {
                auto [temp, idx] = deck.top();
                res[idx] = i-idx;
                deck.pop();
            } 
            deck.push( {temperatures[i], i} );
        }
        return res;
    }
};