





class Solution 
{
    public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        if (nums.empty()) return {};
        sort(nums.begin(), nums.end());
        vector<int> currPath;
        dfs(currPath, 0, target, 4, 0, nums);
        return res;
    }
    
    private:
    vector<vector<int>> res;
    void dfs(vector<int>& currPath, long long currSum, long long target, int k, int start, const vector<int>& options)
    {
        // base case
        if (k == 2) {
            // do twoSum in a sorted array
            int left = start, right = options.size()-1;
            while (left < right) {
                int twoSum = options[left]+options[right];
                if (twoSum > target) {
                    right--;
                } else if (twoSum < target) {
                    left++;
                } else {
                    // a valid quadruplets
                    currPath.push_back(options[left]);
                    currPath.push_back(options[right]);
                    res.push_back(currPath);
                    currPath.pop_back();
                    currPath.pop_back();

                    // move pointer forward
                    left++;
                    right--;
                    while (left<right && options[left] == options[left-1]) left++;
                    while (left<right && options[right] == options[right+1]) right--;
                }
            } 
            return;
        }

        for (int i=start; i<options.size(); i++) {
            if (i > start && options[i] == options[i-1]) continue;

            currPath.push_back(options[i]);
            dfs(currPath, currSum + options[i], target-options[i], k-1, i+1, options);
            currPath.pop_back();
        }
    }
};