class Solution 
{
    public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        if (mat.empty()) return {};
        int ROW = mat.size();
        int COL = mat[0].size();
        vector<pair<int, int>> DIRS = { {0,1}, {0,-1}, {1,0}, {-1,0} };

        vector<vector<int>> res(ROW, vector<int>(COL, -1)); 
        vector<vector<bool>> visited(ROW, vector<bool>(COL, false));
        queue<pair<int, int>> q;

        // seed all 0
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (mat[r][c] == 0) {
                    q.push( {r, c} );
                    visited[r][c] = true;
                    res[r][c] = 0;
                }
            }
        }

        int dist = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto [r, c] = q.front(); q.pop();

                // if 1, fill the dist
                if (mat[r][c] == 1) res[r][c] = dist;

                for (auto& DIR : DIRS) {
                    int newR = r + DIR.first;
                    int newC = c + DIR.second;
                    if (newR<0 || newR>=ROW || newC<0 || newC >= COL) continue;
                    if (visited[newR][newC]) continue;

                    visited[newR][newC] = true;
                    q.push( {newR, newC} );
                }
            }
            dist++;
        }
        return res;
    }
};