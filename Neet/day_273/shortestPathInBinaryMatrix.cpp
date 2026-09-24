class Solution 
{
    public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return -1;
        int ROW = grid.size();
        int COL = grid[0].size();
        if (grid[0][0] != 0 || grid[ROW-1][COL-1] != 0) return -1;

        vector<pair<int, int>> DIRS = { {0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {-1,-1}, {1,-1}, {-1,1} };
        queue<pair<int, int>> q;
        q.push( {0, 0} );
        vector<vector<bool>> visited(ROW, vector<bool>(COL, false));
        visited[0][0] = true;
        
        int len = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto [r, c] = q.front(); q.pop();

                if (r == ROW-1 && c == COL-1) return len;

                for (auto& DIR : DIRS) {
                    int newR = r + DIR.first;
                    int newC = c + DIR.second;
                    if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
                    if (grid[newR][newC] != 0) continue;
                    if (visited[newR][newC]) continue;
                    
                    visited[newR][newC] = true;
                    q.push( {newR, newC} );
                }
            }
            len++;
        }
        return -1;
    }
};