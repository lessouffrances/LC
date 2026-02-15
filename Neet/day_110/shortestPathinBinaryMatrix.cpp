class Solution 
{
    public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return 0;
        
        int ROW = grid.size();
        int COL = grid[0].size();
        vector<pair<int, int>> DIRS = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,1}, {-1,-1},{1,-1}};
        if (grid[0][0] == 1 || grid[ROW-1][COL-1] == 1) return -1;

        queue<pair<int, int>> q;
        q.push( {0, 0} );
        set<pair<int, int>> visited;
        visited.insert( {0, 0} );
        int count = 1;

        while (!q.empty()) {
            int size = q.size();

            for (int i=0; i<size; i++) {
                auto [r, c] = q.front();
                q.pop();
                if (r == ROW-1 && c == COL-1) return count;

                for (auto& DIR : DIRS) {
                    int newR = r + DIR.first;
                    int newC = c + DIR.second;
                    if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
                    if (grid[newR][newC] == 1) continue;
                    if (visited.count( {newR, newC} )) continue;
                    visited.insert( {newR, newC} );
                    q.push( {newR, newC} );
                }
            }
            count++;
        }
        return -1;
    }
};