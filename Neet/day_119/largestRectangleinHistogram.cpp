class Solution 
{
    public:
    int largestRectangleArea(vector<int>& heights) 
    {
        if (heights.empty()) return 0;
        int n = heights.size();
        stack<pair<int, int>> deck; // { idx, height }

        int maxRec = INT_MIN;
        for (int i=0; i<n; i++) {
            int start = i;
            int h = heights[i];

            while (!deck.empty() && h < deck.top().second) {
                auto [idx, height] = deck.top();
                deck.pop();
                maxRec = max(maxRec, (i-idx)*height);
                start = idx;
            }
            deck.push( {start, h} );
        }

        while (!deck.empty()) {
            auto [idx, height] = deck.top();
            maxRec = max(maxRec, (n-idx)*height);
            deck.pop();
        }
        return maxRec;
    }
};