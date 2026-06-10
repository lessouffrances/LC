//          i
//  0,1,2,3,4,5
// [2,1,5,6,2,3]
// maxArea = 10
// start = 2
// stack = {1,1},{4,2},{5,3}


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
            deck.pop();
            maxRec = max(maxRec, (n-idx)*height);
        }

        return maxRec;
    }
};