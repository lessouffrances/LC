class Solution 
{
    public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {
        if (maze.empty()) return -1;

        int ROW = maze.size();
        int COL = maze[0].size();

        vector<pair<int, int>> DIRS = { {0,1}, {0,-1}, {1,0}, {-1,0} };
        vector<vector<bool>> visited(ROW, vector<bool>(COL, false));
        queue<pair<int, int>> q;

        int startRow = entrance[0], startCol = entrance[1];
        q.push( {startRow, startCol} );
        visited[startRow][startCol] = true;

        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            steps++;

            for (int i=0; i<size; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (auto& DIR : DIRS) {
                    int newR = r+DIR.first;
                    int newC = c+DIR.second;

                    if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
                    if (visited[newR][newC]) continue;
                    if (maze[newR][newC] == '+') continue;

                    bool isBorder = (newR == 0 || newR == ROW-1 || newC == 0 || newC == COL-1);
                    if (isBorder) {
                        return steps;
                    } 
                    visited[newR][newC] = true;
                    q.push( {newR, newC} );
                }
            }
        }
        return -1;
    }
};