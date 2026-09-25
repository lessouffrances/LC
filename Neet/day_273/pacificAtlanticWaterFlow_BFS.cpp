class Solution 
{
    public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        // seed all pacific coords
        int ROW = heights.size();
        int COL = heights[0].size();
        vector<pair<int, int>> DIRS = { {0,1}, {0,-1}, {1,0}, {-1,0} };

        auto bfs = [&](queue<pair<int, int>> q){
            set<pair<int, int>> reachables;
            while (!q.empty()) {
                auto [r, c] = q.front(); q.pop();
                if (reachables.count( {r, c} )) continue;
                reachables.insert( {r, c} );

                for (auto& DIR : DIRS) {
                    int newR = r + DIR.first;
                    int newC = c + DIR.second;
                    if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
                    if (heights[newR][newC] < heights[r][c]) continue;
                    if (reachables.count({newR, newC})) continue;
                    q.push({newR, newC});
                }
            }
            return reachables;
        };

        queue<pair<int,int>> pq, aq;
        // seed 
        for (int c=0; c<COL; c++) { pq.push({0, c}); aq.push({ROW-1, c}); }
        for (int r=0; r<ROW; r++) { pq.push({r, 0}); aq.push({r, COL-1}); }

        auto pacificReachables = bfs(pq);
        auto atlanticReachables = bfs(aq);
        
        vector<vector<int>> res;
        
        for (auto& [r, c] : pacificReachables) {
            if (atlanticReachables.count({r, c})) {
                res.push_back({r, c});
            }
        }
        return res;
    }    
};