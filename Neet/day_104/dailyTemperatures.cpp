




//                [1,1,4,2,1,1,0,0]
//                [1   1  4  2  1  1      ]
// temperatures = [73,74,75,71,69,72,76,73]

// deck = { {76,6},{73,7}}


class Solution 
{
    public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        if (temperatures.empty()) return {};
        int n = temperatures.size();

        vector<int> answer(n, 0);
        stack<pair<int, int>> deck;
        for (int i=0; i<n; i++) {
            while (!deck.empty() && temperatures[i] > deck.top().first) {
                auto& [temp, prevIdx] = deck.top();
                deck.pop();
                answer[prevIdx] = (i - prevIdx);
            }
            deck.push( {temperatures[i], i} );
        }
        return answer;
    }
};