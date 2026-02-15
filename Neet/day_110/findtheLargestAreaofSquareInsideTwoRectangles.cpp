class Solution 
{
    public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) 
    {
        if (bottomLeft.empty() || topRight.empty()) return 0;
        int n = bottomLeft.size();

        long long maxSquare = 0;
        for (int i=0; i<n; i++) {
            // bottomLeft
            int x1_prev = bottomLeft[i][0];
            int y1_prev = bottomLeft[i][1];

            // topRight
            int x2_prev = topRight[i][0];
            int y2_prev = topRight[i][1];

            for (int j=0; j<n; j++) {
                if (j == i) continue;
                // bottomLeft
                int x1 = bottomLeft[j][0];
                int y1 = bottomLeft[j][1];
                
                // topRight
                int x2 = topRight[j][0];
                int y2 = topRight[j][1];

                int bottomLeft_x = max(x1_prev, x1);
                int bottomLeft_y = max(y1_prev, y1);
                int topRight_x = min(x2_prev, x2);
                int topRight_y = min(y2_prev, y2);

                if (bottomLeft_x > topRight_x || bottomLeft_y > topRight_y) continue;
                int width = topRight_x - bottomLeft_x;
                int height = topRight_y - bottomLeft_y;
                int side = min(width, height);

                maxSquare = max(maxSquare, (long long) side*side);
            }
        }
        return maxSquare;
    }
};