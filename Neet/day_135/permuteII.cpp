


// Time: O(n · n!)
// n! permutations, each takes O(n) to copy into res → O(n · n!)
// The swap operations themselves are O(1) per node in the recursion tree, 
// which has fewer nodes than n · n!, so copying dominates

// Space: O(n · n!)
// res stores n! permutations each of length n → O(n · n!)
// Recursion stack depth is O(n) (one frame per swap level), 
// which is negligible compared to output storage

class Solution 
{
    public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        // need to skip dups, so sort
        sort(nums.begin(), nums.end());
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

        unordered_set<int> seen;
        for (int i=start; i<nums.size(); i++) {
            // if the same number has been swapped to the start
            if (seen.count(nums[i])) continue;  
            seen.insert(nums[i]);
            swap(nums[i], nums[start]);
            dfs(start+1, nums);
            swap(nums[i], nums[start]);
        }
    }
};