class Solution 
{
    public:
    int trapRainWater(vector<vector<int>>& heightMap) 
    {
        if (heightMap.empty()) return -1;

        int ROW = heightMap.size();
        int COL = heightMap[0].size();

        priority_queue<tuple<int, int, int>,
                    vector<tuple<int, int, int>>,
                    greater<tuple<int, int, int>>> pq; // { height, row, col }

        vector<vector<bool>> visited(ROW, vector<bool>(COL, false));

        // push all boundary cells onto tyhe pq
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (r==0 || r==ROW-1 || c==0 || c==COL-1) {
                    visited[r][c] = true;
                    pq.push( {heightMap[r][c], r, c} );
                }
            }
        }

        vector<pair<int, int>> DIRS = {{0,1},{0,-1},{1,0},{-1,0}};
        int maxHeight = INT_MIN;
        int water = 0;
        while (!pq.empty()) {
            auto [height, r, c] = pq.top();
            pq.pop();

            maxHeight = max(height, maxHeight);
            for (auto& DIR : DIRS) {
                int newR = r + DIR.first;
                int newC = c + DIR.second;

                if (newR<0 || newR>=ROW || newC<0 || newC>= COL || visited[newR][newC] == true) continue;
                if (heightMap[newR][newC] < maxHeight) {
                    water += (maxHeight-heightMap[newR][newC]);
                }
                visited[newR][newC] = true;
                pq.push( {heightMap[newR][newC], newR, newC} );
            }
        }
        return water;
    }
};