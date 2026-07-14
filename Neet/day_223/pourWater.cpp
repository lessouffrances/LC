class Solution 
{
    public:
    vector<int> pourWater(vector<int>& heights, int volume, int k) 
    {
        int n = heights.size();
        // the dirs that one waterdrop can go
        vector<int> DIRS = {-1, 1};

        // water drops one by one
        for (int v=0; v<volume; v++) {
            bool placed = false;
            for (int DIR : DIRS) {
                int pos = k, best = k;

                // the while loop means that the water can keep flowing
                while (pos+DIR >= 0 && pos+DIR < n && heights[pos+DIR] <= heights[pos]) {
                    if (heights[pos+DIR] < heights[pos]) best = pos+DIR;
                    pos += DIR; // change the pos, keep flowing
                }

                if (best != k) {
                    heights[best]++; // consolidate the result
                    placed = true;
                    break;
                }
            }
            if (!placed) heights[k]++;
        }
        return heights;
    }
};