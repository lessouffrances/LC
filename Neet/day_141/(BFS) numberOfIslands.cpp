





class Solution 
{
    public:
    int numIslands(vector<vector<char>>& grid) 
    {
        if (grid.empty()) return 0;

        ROW = grid.size();
        COL = grid[0].size();

        int numberOfIslands = 0;
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (grid[r][c] == '1') {
                    bfs(r, c, grid);
                    numberOfIslands++;
                }
            }
        }
        return numberOfIslands;
    }

    private:
    int ROW, COL;
    vector<pair<int, int>> DIRS = { {0,1}, {0,-1}, {1,0}, {-1,0} };
    void bfs(int row, int col, vector<vector<char>>& grid)
    {
        queue<pair<int, int>> q;
        q.push( {row, col} );

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto& DIR : DIRS) {
                int newR = r + DIR.first;
                int newC = c + DIR.second;

                if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
                if (grid[newR][newC] != '1') continue;
                
                q.push( {newR, newC} );
                grid[newR][newC] = '2';
            }
        }
    }
};