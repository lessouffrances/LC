
// heights = [4,2,3,1]
// [0,

class Solution 
{
    public:
    vector<int> findBuildings(vector<int>& heights) 
    {
        if (heights.empty()) return {};
        int n = heights.size();

        vector<int> res;
        stack<int> deck; // store indexes

        for (int i=0; i<n; i++) {
            while (!deck.empty() && heights[deck.top()] <= heights[i]) {
                deck.pop();
            }
            deck.push(i);
        }

        // remain on stack 
        while (!deck.empty()) {
            res.push_back(deck.top());
            deck.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};