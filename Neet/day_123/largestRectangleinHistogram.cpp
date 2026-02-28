class Solution 
{
    public:
    int largestRectangleArea(vector<int>& heights) 
    {
        if (heights.empty()) return 0;
        int n = heights.size();

        stack<pair<int, int>> deck; // { idx, height }
        for (int i=0; i<n; i++) {
            int start = i;
            int h = heights[i];

            // stack exit: when I see a height that's lower than the prev one,
            // which means,
            // need to consolidate stack 
            int maxRec = 0;
            while (!deck.empty() && h < deck.top().second) {
                auto [idx, height] = deck.top();
                deck.pop();

                // consolidate the prev height on stack
                maxRec = max(maxRec, (i-idx)*height);
                start = idx;
            }
            deck.push( {start, h} );
        }

        while (!deck.empty()) {
            auto [idx, height] = deck.top();
            deck.pop();
            // consolidate the prev height on stack
            maxRec = max(maxRec, (n-idx)*height);
        }
        return maxRec;
    }
};