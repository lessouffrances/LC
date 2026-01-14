class Solution
{
    public:
    void wallsAndGates(vector<vector<int>>& rooms)
    {
        if (rooms.empty()) return;
        ROW = rooms.size();
        COL = rooms[0].size();

        // collect multisource
        for (int r=0; r<ROW; r++) {
            for (int c=0; c<COL; c++) {
                if (rooms[r][c] == 0) {
                    GATES.insert( {r, c} );
                }
            }
        }

        bfs(rooms);
    }

    private:
    int ROW, COL;
    set<pair<int, int>> GATES;
    vector<pair<int, int>> DIRS = {{0,1},{0,-1},{1,0},{-1,0}};
    void bfs(vector<vector<int>>& rooms)
    {
        queue<pair<int, int>> q;
        set<pair<int, int>> visited;
        for (auto& [r, c] : GATES) {
            q.push( {r, c} );
            visited.insert( {r, c} );
        }
        

        int dist = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto [r, c] = q.front();
                q.pop();

                if (dist != 0) {
                    rooms[r][c] = dist;
                }

                for (auto& DIR : DIRS) {
                    int newR = r + DIR.first;
                    int newC = c + DIR.second;

                    if (newR<0 || newR>= ROW || newC<0 || newC>=COL) continue;
                    if (visited.count({newR, newC})) continue;
                    if (rooms[newR][newC] == -1 || rooms[newR][newC] == 0) continue;

                    visited.insert( {newR, newC} );
                    q.push( {newR, newC} );
                }
            }
            dist++;
        }
      
    }
};
