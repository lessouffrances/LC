class Solution 
{
    public:
    int numIslands(vector<vector<char>>& grid) 
    {
        if (grid.empty()) return 0;
        ROW = grid.size();
        COL = grid[0].size();

        int numOfIslands = 0;
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (grid[r][c] == '1') {
                    grid[r][c] = '2';
                    bfs(r, c, grid);
                    numOfIslands++;
                }
            }
        }
        return numOfIslands;
    }
    private:
    vector<pair<int, int>> DIRS = {{0,1},{0,-1},{1,0},{-1,0}};
    int ROW, COL;
    void bfs(int row, int col, vector<vector<char>>& grid)
    {
        queue<pair<int, int>> q;
        q.push( {row, col} );
        grid[row][col] = '2'; // mark visited

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto& DIR : DIRS) {
                int newR = row + DIR.first;
                int newC = col + DIR.second;

                if (newR<0 || newR>=ROW || newC<0 || newC>= COL) continue;
                if (grid[newR][newC] != '1') continue;
        
                grid[newR][newC] = '2'; // mark visited
                q.push( {newR, newC} );
            }
        }
    }
};