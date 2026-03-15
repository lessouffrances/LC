


class Solution 
{
    public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        if (grid.empty()) return -1;
        int n = grid.size();
        if (grid[n-1][n-1] == 1 || grid[0][0] == 1) return -1;
        vector<pair<int, int>> DIRS = { {0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1} };

        queue<pair<int, int>> q;
        set<pair<int, int>> visited;
        q.push( {0, 0} );
        int length = 1;

        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto [r, c] = q.front();
                q.pop();

                if (r == n-1 && c == n-1) return length;

                for (auto& DIR : DIRS) {
                    int newR = DIR.first + r;
                    int newC = DIR.second + c;

                    if (newR<0 || newR>=n || newC<0 || newC>=n) continue;
                    if (visited.count( {newR, newC} )) continue;
                    if (grid[newR][newC] != 0) continue;

                    q.push( {newR, newC} );
                    visited.insert( {newR, newC});
                }
            }
            length++;
        }
        return -1;
    }
};