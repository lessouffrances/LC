






class Solution 
{
    public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        if (temperatures.empty()) return {};
        int n = temperatures.size();
        vector<int> answer(n);

        stack<int> deck;
        for (int i=0; i<n; i++) {
            while (!deck.empty() && temperatures[i] > temperatures[deck.top()]) {
                int prevIdx = deck.top();
                deck.pop();
                answer[prevIdx] = i - prevIdx;
            }
            deck.push(i);
        }
        return answer;
    }
};