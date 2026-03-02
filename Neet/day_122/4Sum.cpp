


// O(n ^ (k-1)): for k-sum
class Solution 
{
    public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        vector<int> currPath;
        dfs(currPath, 0, 4, target, nums);
        return res;
    }

    private:
    vector<vector<int>> res;
    void dfs(vector<int>& currPath, int start, int k, int target, vector<int>& options)
    {
        // base case: twoSum
        int n = options.size();
        if (k == 2) {
            int left = start, right = n-1;

            // twoSum
            while (left < right) {
                int twoSum = options[left] + options[right];
                if (twoSum > target) {
                    left++;
                } else if (twoSum < target) {
                    right--;
                } else {
                    currPath.push_back(options[left]);
                    currPath.push_back(options[right]);
                    res.push_back(currPath); 
                    currPath.pop_back();
                    currPath.pop_back();
                    left++;
                    right--;
                    // skip duplicates
                    while (left < right && options[left] == options[left-1]) left++;
                    while (left < right && options[right] == options[right+1]) right--;
                }
            }
            return;
        }
        
        for (int i=start; i<options.size(); i++) {
            if (i>start && options[i] == options[i-1]) continue;
            currPath.push_back(options[i]);
            dfs(currPath, i+1, k-1, target-options[i], options);
            currPath.pop_back();
        }
    }
};
        