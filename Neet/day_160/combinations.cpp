



class Solution 
{
    public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> currPath; 
        dfs(1, 0, currPath, n, k);
        return res;
    }

    private:
    vector<vector<int>> res;
    void dfs(int currNum, int currSize, vector<int>& currPath, int n, int k)
    {
        if (currSize == k) {
            res.push_back(currPath);
            return;
        }
        if (currNum > n) return;

        // take the currNum
        currPath.push_back(currNum);
        dfs(currNum+1, currSize+1, currPath, n, k);
        currPath.pop_back();

        // skip
        dfs(currNum+1, currSize, currPath, n, k);
    }
};