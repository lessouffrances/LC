class Solution 
{
    public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int ROW = grid.size();
        int COL = grid[0].size();

        vector<pair<int, int>> DIRS = { {0,1}, {0,-1}, {1,0}, {-1,0} };
        queue<pair<int, int>> q;

        // multi-source BFS
        // push all rotted oranges onto the q
        int numOfFreshOranges = 0;
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (grid[r][c] == 2) {
                    q.push( {r, c} );
                }
                if (grid[r][c] == 1) {
                    numOfFreshOranges++;
                }
            }
        }

        int minutes = 0;
        while (!q.empty()) {
            int size = q.size();
            bool hasInfected = false;

            for (int i=0; i<size; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (auto& DIR : DIRS) {
                    int newR = r + DIR.first;
                    int newC = c + DIR.second;

                    if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
                    if (grid[newR][newC] != 1) continue;
                    hasInfected = true;
                    grid[newR][newC] = 2;
                    q.push( {newR, newC} );
                    numOfFreshOranges--;
                }
            }
            if (hasInfected) minutes++;
        }
        return numOfFreshOranges == 0 ? minutes : -1;
    }
};