class Solution 
{
    public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        if (temperatures.empty()) return {};

        stack<int> deck; // idx
        int n = temperatures.size();

        vector<int> res(n, 0);
        for (int i=0; i<n; i++) {
            while (!deck.empty() && temperatures[i] > temperatures[deck.top()]) {
                auto prevIdx = deck.top();
                deck.pop();

                res[prevIdx] = (i-prevIdx);
            }
            deck.push(i);
        }
        return res;
    }
};