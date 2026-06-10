class Solution 
{
    public:
    int trapRainWater(vector<vector<int>>& heightMap) 
    {
        if (heightMap.empty()) return 0;
        int ROW = heightMap.size();
        int COL = heightMap[0].size();
        vector<pair<int, int>> DIRS = { {0,1}, {1,0}, {-1,0}, {0,-1} };
        vector<vector<bool>> visited(ROW, vector<bool>(COL, false));

        // must be a minHeap! {height, r, c}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        // push all bordered onto the q
        // top && bottom row
        for (int c=0; c<COL; c++) {
            pq.push( {heightMap[0][c], 0, c} );
            visited[0][c] = true;
            pq.push( {heightMap[ROW-1][c], ROW-1, c} );
            visited[ROW-1][c] = true;
        }

        // left && right col
        for (int r=0; r<ROW; r++) {
            pq.push( {heightMap[r][0], r, 0} );
            visited[r][0] = true;
            pq.push( {heightMap[r][COL-1], r, COL-1} );
            visited[r][COL-1] = true;
        }

        int maxHeight = INT_MIN;
        int water = 0;
        while (!pq.empty()) {
            auto [height, r, c] = pq.top();
            pq.pop();
            maxHeight = max(maxHeight, height);

            for (auto& DIR : DIRS) {
                int newR = r + DIR.first;
                int newC = c + DIR.second;

                if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
                if (visited[newR][newC] == true) continue;
                water += max(0, maxHeight-heightMap[newR][newC]);
                visited[newR][newC] = true;
                pq.push( {heightMap[newR][newC], newR, newC});
            }
        }
        return water;
    }
};