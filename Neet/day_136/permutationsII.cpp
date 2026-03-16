



// Time: O(n! · n) worst case (all unique)
// With duplicates, pruning reduces the number of leaf nodes to n! / (c1! · c2! · ... · ck!) 
// where ci are the counts of each duplicate group 
// — but the bound stays O(n! · n) in the worst case
// The · n factor is for copying each permutation into res

// Space: O(n! · n)
// res stores all unique permutations, each of length n
// Recursion stack: O(n)
// seen sets: O(n) per level × O(n) levels = O(n²) auxiliary, negligible
// Output dominates

class Solution 
{
    public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        if (nums.empty()) return {};
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
            if (seen.count(nums[i])) continue;
            seen.insert(nums[i]);

            swap(nums[i], nums[start]);
            dfs(start+1, nums);
            swap(nums[i], nums[start]); // backtrack
        }
    }
};