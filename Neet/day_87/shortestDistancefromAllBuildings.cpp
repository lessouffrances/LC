class Solution 
{
    public:
    int shortestDistance(vector<vector<int>>& grid)
    {
        if (grid.empty()) return 0;
        ROW = grid.size();
        COL = grid[0].size();

        vector<vector<int>> reachCount(ROW, vector<int>(COL, 0));
        vector<vector<int>> distance(ROW, vector<int>(COL, 0));

        int numOfBuildings = 0;
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (grid[r][c] == 1) {
                    bfs(r, c, reachCount, distance, grid);
                    numOfBuildings++;
                }
            }
        }

        int minDist = INT_MAX;
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (grid[r][c] == 0 && reachCount[r][c] == numOfBuildings) {
                    minDist = min(distance[r][c], minDist);
                }
            }
        }
        return minDist == INT_MAX ? -1 : minDist;
    }
    private:
    int ROW, COL;
    vector<pair<int, int>> DIRS = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    void bfs(int row, int col, vector<vector<int>>& reachCount, 
        vector<vector<int>>& distance, vector<vector<int>>& grid)
    {
        queue<pair<int, int>> q;
        q.push( {row, col} );

        vector<vector<bool>>visited(ROW, vector<bool>(COL, false));
        visited[row][col] = true;

        int dist = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (auto& DIR : DIRS) {
                    int newR = r + DIR.first;
                    int newC = c + DIR.second;

                    if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
                    if (visited[newR][newC] == true) continue;
                    if (grid[newR][newC] != 0) continue;

                    reachCount[newR][newC]++;
                    distance[newR][newC] += dist;
                    visited[newR][newC] = true;
                    q.push( {newR, newC} );
                }
            }
            dist++;
        }
    }
};