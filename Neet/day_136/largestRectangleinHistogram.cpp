

// Time: O(N)
// Space: O(N)

class Solution 
{
    public:
    int largestRectangleArea(vector<int>& heights) 
    {
        if (heights.empty()) return 0;
        int n = heights.size();

        stack<pair<int, int>> deck; // { idx, height }
        int maxRec = 0;

        for (int i=0; i<n; i++) {
            int start = i; // leftmost index the current bar can extend to
            int h = heights[i];

            // drop in height
            // stack exit
            while (!deck.empty() && h < deck.top().second) {
                // consolidate the stack
                // the h cannot be extended back to start
                auto [idx, height] = deck.top();
                deck.pop();

                maxRec = max(maxRec, (i-idx)*height);
                start = idx;
            }
            // enter stack 
            deck.push( {start, h} );
        }

        // consolidate stack
        while (!deck.empty()) {
            auto [idx, height] = deck.top();
            deck.pop();
            maxRec = max(maxRec, (n-idx)*height);
        }
        return maxRec;
    }
};