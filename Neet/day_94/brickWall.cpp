class Solution 
{
    public:
    int leastBricks(vector<vector<int>>& wall) 
    {
        if (wall.empty()) return 0;

        unordered_map<long long, int> edgeCount; // { pos : edgeCount } 
        int maxEdges = 0;

        for (auto& row : wall) {
            long long position = 0;
            for (int i=0; i < row.size()-1; i++) {
                position += row[i];
                edgeCount[position]++;
                maxEdges = max(maxEdges, edgeCount[position]);
            }
        }
        return wall.size() - maxEdges;
    }
};