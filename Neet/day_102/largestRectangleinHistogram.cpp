





//            i
// [2,1,5,6,2,3]
// maxArea = 10
// deck = {1,1},{2,2},{5,3}
// start = 2
// h = 2
// idx = 2
// height = 5


class Solution 
{
    public:
    int largestRectangleArea(vector<int>& heights) 
    {
        if (heights.empty()) return 0;
        int n = heights.size();

        int maxArea = 0;
        stack<pair<int, int>> deck; // idx, h
        for (int i=0; i<n; i++) {
            int start = i;
            int h = heights[i];

            while (!deck.empty() && deck.top().second > h) {
                auto [idx, height] = deck.top();
                deck.pop();

                maxArea = max(maxArea, (i - idx) * height);
                start = idx;
            }
            deck.push( {start, h} );
        }

        while (!deck.empty()) {
            auto [idx, height] = deck.top();
            deck.pop();
            maxArea = max(maxArea, (int)(n-idx) * height);
        }
        return maxArea;

    }
};