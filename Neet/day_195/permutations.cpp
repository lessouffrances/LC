//  s
//  i
// [1,2,3]

// s=0, i=0, 
// [1,2,3] => dfs(1), comp
// s=0, i=1, 
// [2,1,3] => dfs(1), comp

// s=0, i=2, 
// [3,2,1] => dfs(1), comp
// ***********************

// s=1, i=1, 
// [1,2,3] => dfs(2)
// s=1, i=2, 
// [1,3,2] => dfs(2)

// s=1, i=1, 
// [2,1,3] => dfs(2)
// s=1, i=2, 
// [2,3,1] => dfs(2)

// s=1, i=1, 
// [3,2,1] => dfs(2)
// s=1, i=2, 
// [3,1,2] => dfs(2)

// ************************
// s=2, i=3, 
// [1,2,3] => dfs(3) => save [1,2,3]
// s=2, i=3, 
// [1,3,2] => dfs(3) => save [1,3,2]

// s=2, i=3, 
// [2,1,3] => dfs(3) => save [2,1,3]
// s=2, i=3, 
// [2,3,1] => dfs(3) => save [2,3,1]

// s=2, i=3, 
// [3,2,1] => dfs(3) => save [3,2,1]
// s=1, i=3, 
// [3,1,2] => dfs(3) => save [3,1,2]


class Solution 
{
    public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        dfs(0, nums);
        return res;
    }
    private:
    vector<vector<int>> res;
    void dfs(int start, vector<int>& nums)
    {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i=start; i<nums.size(); i++) {
            swap(nums[start], nums[i]);
            dfs(start+1, nums);
            swap(nums[start], nums[i]); // backtrack
        }
    }
};