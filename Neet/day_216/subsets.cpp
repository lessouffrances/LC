
//         []
//       /    \
//    [1]     []
//   /  \     / \
// [1,2][1]  [2] []
//[1,2,3],[1,2],[1,3],[1],[2,3],[2],[3],[]


class Solution 
{
    public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        if (nums.empty()) return { {} };

        vector<int> currPath = {};
        dfs(0, currPath, nums);
        return res;
    }

    private:
    vector<vector<int>> res;

    void dfs(int currIdx, vector<int>& currPath, vector<int>& nums)
    {
        if (currIdx == nums.size()) {
            res.push_back(currPath);
            return;
        }

        // take 
        currPath.push_back(nums[currIdx]);
        dfs(currIdx+1, currPath, nums);
        currPath.pop_back();

        // skip
        dfs(currIdx+1, currPath, nums);
    }
};