class Solution 
{
    public:
    int swimInWater(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, false));
        vector<pair<int,int>> DIRS = { {1,0},{-1,0},{0,1},{0,-1} };
        
        // minHeap: {gridVal, r, c}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push( {grid[0][0], 0, 0} );
        visited[0][0] = true;
        int minTime = 0;

        while (!pq.empty()) {
            auto [gridVal, r, c] = pq.top();
            pq.pop();

            minTime = max(minTime, gridVal);
            if (r == n-1 && c == n-1) return minTime;

            for (auto& DIR : DIRS) {
                int newR = r + DIR.first;
                int newC = c + DIR.second;
                if (newR<0 || newR>=n || newC<0 || newC>=n) continue;
                if (visited[newR][newC]) continue;
                visited[newR][newC] = true;
                pq.push( {grid[newR][newC], newR, newC} );
            }
        }
        return -1;
    }
};