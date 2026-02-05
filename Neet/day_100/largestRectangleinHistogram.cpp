class Solution 
{
    public:
    int largestRectangleArea(vector<int>& heights) 
    {
        if (heights.empty()) return 0;
        int n = heights.size();
        int maxArea = 0;

        stack<pair<int, int>> deck;
        for (int i=0; i<n; i++) {
            int start = i;
            int h = heights[i];

            // when the next upcoming one is lower, 
            // the last minute to preserve the higher height on deck is now!
            while (!deck.empty() && h < deck.top().second) {
                auto [index, height] = deck.top();
                deck.pop();
                maxArea = max(maxArea, (i - index) * height);
                start = index;
            }
            deck.push( {start, h} );
        }

        while (!deck.empty()) {
            auto [index, h] = deck.top();
            deck.pop();

            maxArea = max(maxArea, (int)(n-index) * h);
        }

        return maxArea;
    }
};