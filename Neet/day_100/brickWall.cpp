






// a line cross minimum bricks is a line crosses most edges

class Solution 
{
    public:
    int leastBricks(vector<vector<int>>& wall) 
    {
        if (wall.empty()) return 0;

        unordered_map<int, int> posToEdge; // record num of edges at the pos
        
        int maxEdges = 0;
        for (auto& row : wall) {
            long long pos = 0;
            for (int i=0; i<row.size()-1; i++) {
                pos += row[i];
                posToEdge[pos]++;
                maxEdges = max(maxEdges, posToEdge[pos]);
            }
        }

        return wall.size() - maxEdges;
    }
};