
// multisource BFS is more efficient 
// seed all gates
class Solution 
{
    public:
    void wallsAndGates(vector<vector<int>>& rooms) 
    {
        if (rooms.empty()) return;
        bfs(rooms);   
    }

    private:
    void bfs(vector<vector<int>>& rooms)
    {
        int ROW = rooms.size();
        int COL = rooms[0].size();
        vector<pair<int, int>> DIRS = { {0,1}, {0,-1}, {1,0}, {-1,0} };
        vector<vector<bool>> visited(ROW, vector<bool>(COL, false));

        queue<pair<int, int>> q;
        // push all gates onto the q
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (rooms[r][c] == 0) {
                    q.push( {r, c} );
                    visited[r][c] = true;
                }
            }
        }

        int dist = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto [r, c] = q.front();
                q.pop();

                // fill the blanks
                if (rooms[r][c] == INT_MAX) {
                    rooms[r][c] = dist;
                }
                for (auto& DIR : DIRS) {
                    int newR = r + DIR.first;
                    int newC = c + DIR.second;

                    if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
                    if (rooms[newR][newC] != INT_MAX) continue;
                    if (visited[newR][newC]) continue;

                    visited[newR][newC] = true;
                    q.push( {newR, newC} );
                }
            }
            dist++;
        }
    }
};