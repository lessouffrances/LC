class Solution 
{
    public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return -1;
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        vector<pair<int, int>> DIRS = {{0,1},{0,-1},{-1,0},{1,0},{1,1},{1,-1},{-1,-1},{-1,1}};
        queue<pair<int, int>> q;
        q.push( {0, 0} );

        int level = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto [r, c] = q.front();
                q.pop();

                if (r == n-1 && c == n-1) return level;

                for (auto& DIR : DIRS) {
                    int newR = r + DIR.first;
                    int newC = c + DIR.second;

                    if (newR<0 || newR>=n || newC<0 || newC>=n) continue;
                    if (grid[newR][newC] != 0) continue;

                    grid[newR][newC] = 2;
                    q.push( {newR, newC} );
                }
            }
            level++;
        }
        return -1;
    }
};