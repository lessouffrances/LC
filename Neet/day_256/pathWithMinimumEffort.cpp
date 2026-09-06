class Solution 
{
    public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        if (heights.empty()) return 0;
        ROW = heights.size();
        COL = heights[0].size();
        int left = 0, right = 1000000;  // max possible height difference
        int res = right;

        while (left <= right) {
            int mid = left + (right-left)/2;
            visited.assign(ROW, vector<bool>(COL, false));  
            if (dfs(0, 0, mid, heights)) {
                res = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return res;
    }

    private:
    int ROW, COL;
    vector<vector<bool>> visited;
    vector<pair<int,int>> DIRS = { {0,1},{0,-1},{1,0},{-1,0} };
    bool dfs(int row, int col, int maxEffort, vector<vector<int>>& heights)
    {
        // base case
        if (row == ROW-1 && col == COL-1) return true;
        visited[row][col] = true;

        for (auto& DIR : DIRS) {
            int newR = row+DIR.first;
            int newC = col+DIR.second;

            if (newR<0 || newR>=ROW || newC<0 || newC>=COL) continue;
            if (visited[newR][newC]) continue;
            int diff = abs(heights[newR][newC]-heights[row][col]);
            if (diff > maxEffort) continue;

            if (dfs(newR, newC, maxEffort, heights)) return true;
        }
        return false;
    }
};