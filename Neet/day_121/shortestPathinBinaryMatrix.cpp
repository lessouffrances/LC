class Solution 
{
    public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int ROW = grid.size();;
        int COL = grid[0].size();
        vector<pair<int, int>> DIRS = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,1}, {-1,-1},{1,-1}};

        // if the start or the end was blocked
        if (grid[0][0] == 1 || grid[ROW-1][COL-1] == 1) return -1;

        queue<pair<int, int>> q;
        q.push( {0, 0} );
        grid[0][0] = 2; // 2 mark as visited

        int minLen = 1;
        while (!q.empty()) {
            int size = q.size();

            bool isGoThru = false;
            for (int i=0; i<size; i++) {
                auto [r, c] = q.front();
                q.pop();

                if (r == ROW-1 && c == COL-1) return minLen;

                for (auto& DIR : DIRS) {
                    int newR = r + DIR.first;
                    int newC = c + DIR.second;

                    if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
                    if (grid[newR][newC] != 0) continue;

                    q.push( {newR, newC} );
                    grid[newR][newC] = 2; // visited
                    isGoThru = true;
                }
            }
            if (isGoThru) minLen++;
        }
        return -1;
    }
};