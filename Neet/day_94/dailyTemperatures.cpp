class Solution 
{
    public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        if (temperatures.empty()) return {};

        int n = temperatures.size();
        vector<int> res(n);
        stack<int> deck;

        for (int i=0; i<n; i++) {
            while (!deck.empty() && temperatures[i] > temperatures[deck.top()]) {
                int prevIdx = deck.top();
                deck.pop();
                res[prevIdx] = i - prevIdx; // days waiting
            }
            deck.push(i);
        }
        return res;
    }
};