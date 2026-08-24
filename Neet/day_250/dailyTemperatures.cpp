
// temperatures = [73,74,75,71,69,72,76,73]
// stack = [ {2,75}, {3,71}, {4,69}, {5,72}]

class Solution 
{
    public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        if (temperatures.empty()) return {};

        int n = temperatures.size();
        stack<pair<int, int>> deck; // { temp, idx }
        vector<int> answer(n, 0); 
        for (int i=0; i<n; i++) {
            while (!deck.empty() && temperatures[i] > deck.top().first) {
                int daysWait = i - deck.top().second;
                answer[deck.top().second] = daysWait;
                deck.pop();
            }
            deck.push( {temperatures[i], i} );
        }
        return answer;
    }
};