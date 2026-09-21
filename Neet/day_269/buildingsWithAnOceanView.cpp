

// heights = [4,2,3,1], ocean
// stack = [4,3,1]
// push to the stack as usual,
// when the next element is higher than the deck.top(),
// we know that the deck.top() is not a building with an ocean view, push to the res
// push the next element and continue

class Solution 
{
    public:
    vector<int> findBuildings(vector<int>& heights) 
    {
        if (heights.empty()) return {};
        int n = heights.size();

        vector<int> res;
        stack<int> deck; // the indexes of buildings
        for (int i=0; i<n; i++) {
            while (!deck.empty() && heights[i] >= heights[deck.top()]) {
                deck.pop();
            } 
            deck.push(i);
        }

        while (!deck.empty()) {
            res.push_back(deck.top());
            deck.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};