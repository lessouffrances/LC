class Solution 
{
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) 
    {
        if (preferences.empty() || pairs.empty()) return 0;

        // rank[i][j] = the rank that person i gives to person j
        vector<vector<int>> rank(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n-1; j++) {  
                rank[i][preferences[i][j]] = j;
            }
        }

        // Map each person to their paired partner
        vector<int> partner(n);
        for (const auto& pair : pairs) {
            partner[pair[0]] = pair[1];
            partner[pair[1]] = pair[0];
        }

        int unhappyCount = 0;
        for (int x = 0; x < n; x++) {
            int y = partner[x];

            for (int u = 0; u < n; u++) {
                if (u == x || u == y) continue;

                int v = partner[u];

                if (rank[x][u] < rank[x][y] && rank[u][x] < rank[u][v]) {
                    unhappyCount++;
                    break;
                }
            }
        }
        return unhappyCount;
    }
};