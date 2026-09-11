// temperatures = [73,74,75,71,69,72,76,73]

class Solution 
{
    public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        if (temperatures.empty()) return {};
        int n = temperatures.size();

        stack<pair<int, int>> deck; // {idx, temp}
        // idx is for answer to refer

        vector<int> res(n,0);
        for (int i=0; i<n; i++) {
            while (!deck.empty() && temperatures[i] > deck.top().second) {
                auto [idx, temp] = deck.top();
                res[idx] = i-idx;
                deck.pop();
            }
            deck.push( {i, temperatures[i]} );
        }
        return res;
    }
};