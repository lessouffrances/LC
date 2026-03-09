class Solution 
{
    public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return 0;
        int ROW = grid.size();
        int COL = grid[0].size();
        vector<pair<int, int>> DIRS = {{0,1},{0,-1},{1,0},{-1,0}};

        // push all rotted oranges onto q
        // count all fresh oranges
        queue<pair<int, int>> q;
        int numOfFreshOranges = 0;
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (grid[r][c] == 1) {
                    numOfFreshOranges++;
                } else if (grid[r][c] == 2) {
                    q.push( {r, c} ); // push rotted oranges onto the q
                }
            }
        }

        int minutes = 0;
        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;
            for (int i=0; i<size; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (auto& DIR : DIRS) {
                    int newR = r + DIR.first;
                    int newC = c + DIR.second;

                    if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
                    if (grid[newR][newC] != 1) continue;

                    q.push( {newR, newC} );
                    grid[newR][newC] = 2; // mark visited
                    rotted = true;
                    numOfFreshOranges--;
                }
            }
            if (rotted) minutes++;
        }

        return numOfFreshOranges == 0 ? minutes : -1;
    }
};