

//  0,1,2,3,4,5
// [2,1,5,6,2,3]

// condition to consolidate stack: the about-to-push height < height on top => drop 
//                            
// stack = [ {0,1}, {2,2}, {5,3}  ], { idx, height }

// start equals to: 1) when push to the stack, the i; 2) when consolidate the stack, the idx
// maxRec = (4-2)*5 = 10
// start = 2
// h = 2


class Solution 
{
    public:
    int largestRectangleArea(vector<int>& heights) 
    {
        if (heights.empty()) return 0;

        stack<pair<int, int>> deck;
        int maxRec = INT_MIN;

        for (int i=0; i<n; i++) {
            int start = i;
            int h = heights[i];

            while (!deck.empty() && h < deck.top().second()) {
                auto& [idx, height] = deck.top();
                deck.pop();

                maxRec = max(maxRec, (i-idx)*height);
                start = idx;
            }

            deck.push( {start, h} );
        }

        while (!deck.empty()) {
            auto& [idx, height] = deck.top();
            deck.pop();
            maxRec = max(maxRec, (n-idx)*height);
        }
        return maxRec;
    }
};