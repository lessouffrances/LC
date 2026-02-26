class Solution 
{
    public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        if (grid.size() == 0) return 0;

        int ROW = grid.size();
        int COL = grid[0].size();
        vector<pair<int, int>> DIRS = {{0,1},{0,-1},{1,0},{-1,0}};

        int numOfMinutes = 0;
        int numOfFreshOranges = 0;
        // push all rotted oranges onto the q;
        queue<pair<int, int>> q;
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (grid[r][c] == 2) {
                    // push rotted oranges onto the stack
                    q.push( {r, c} );
                } else if (grid[r][c] == 1) {
                    // the fresh orange
                    numOfFreshOranges++;
                }
            }
        }
        
        while (!q.empty()) {
            int size = q.size();

            bool isRotted = false;
            for (int i=0; i<size; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (auto& DIR : DIRS) {
                    int newR = r + DIR.first;
                    int newC = c + DIR.second;

                    if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
                    if (grid[newR][newC] != 1) continue;

                    grid[newR][newC] = 2; // mark as rotted
                    q.push( {newR, newC} ); 
                    isRotted = true;
                    numOfFreshOranges--;
                } 
            }

            if (isRotted) numOfMinutes++;
        }
        return numOfFreshOranges == 0 ? numOfMinutes : -1;
    }
};