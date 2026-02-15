class Solution 
{
    public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) 
    {
        if (preferences.empty()) return 0;

        // person i will give person j a rank[i][j]
        vector<vector<int>> rank(n, vector<int>(n, 0));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n-1; j++) {
                rank[i][preferences[i][j]] = j; 
            }
        }

        // map each person with their assigned partner
        unordered_map<int, int> partner;
        for (auto& pair : pairs) {
            int x = pair[0];
            int y = pair[1];
            partner[x] = y;
            partner[y] = x;
        }

        int unhappyCount = 0;
        for (auto& [x, y] : partner) {
            int xRankY = rank[x][y];

            for (int u=0; u<n; u++) {
                if (u == x || u == y) continue;
                int xRankU = rank[x][u];
                int v = partner[u];
                int uRankV = rank[u][v];
                int uRankX = rank[u][x];

                if (xRankU < xRankY && uRankX < uRankV) {
                    unhappyCount++;
                    break;
                }
            }
        }
        return unhappyCount;
    }
};