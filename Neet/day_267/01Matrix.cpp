class Solution 
{
    public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        if (mat.empty()) return {};
        int ROW = mat.size();
        int COL = mat[0].size();
        vector<pair<int, int>> DIRS = { {0,1}, {0,-1}, {1,0}, {-1,0} };
        // seed all 0s
        queue<pair<int, int>> q;
        vector<vector<bool>> visited;
        visited.assign(ROW, vector<bool>(COL, false));
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (mat[r][c] == 0) {
                    q.push( {r, c} );
                    visited[r][c] = true;
                }
            }
        }

        int dist = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto [r, c] = q.front(); q.pop();

                if (mat[r][c] == 1) mat[r][c] = dist;

                for (auto& DIR : DIRS) {
                    int newR = r+DIR.first;
                    int newC = c+DIR.second;

                    if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
                    if (visited[newR][newC]) continue;
                    visited[newR][newC] = true;
                    q.push( {newR, newC} );
                }
            }
            dist++;
        }
        return mat;
    }
};