// temperatures = [73,74,75,71,69,72,76,73]
// stack = [ {} ]
// [1,1,4,2,1,1,0,0]

class Solution 
{
    public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n = temperatures.size();
        stack<pair<int, int>> deck; // { temperature, idx }
        vector<int> answer(n, 0);

        for (int i=0; i<n; i++) {
            while (!deck.empty() && temperature[i] > deck.top().first) {
                int waitDays = i - deck.top().second;
                answer[deck.top().second] = waitDays;
                deck.pop();
            } 
            deck.push( {temperature[i], i} );
        }
        return answer;
    }
};