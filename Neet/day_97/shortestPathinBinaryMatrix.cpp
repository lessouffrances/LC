class Solution 
{
    public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return 0;
        
        int ROW = grid.size();
        int COL = grid[0].size();
        if (grid[0][0] == 1 || grid[ROW-1][COL-1] == 1) return -1;
        vector<pair<int, int>> DIRS = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1}};

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1; // mark as visited

        int level = 1;
        while (!q.empty()) {
            int size = q.size();

            for (int i=0; i<size; i++) {
                auto [r, c] = q.front();
                q.pop();

                if (r == ROW-1 && c == COL-1) return level;

                for (auto& DIR : DIRS) {
                    int newR = r + DIR.first;
                    int newC = c + DIR.second;

                    if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
                    if (grid[newR][newC] != 0) continue;
                    q.push( {newR, newC} );
                    grid[newR][newC] = 1;
                }
            }
            level++;
        }
        return -1;
    }
};