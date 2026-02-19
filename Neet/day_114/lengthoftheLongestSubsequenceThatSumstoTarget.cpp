



class Solution 
{
    public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) 
    {
        if (nums.empty()) return -1;

        sort(nums.rbegin(), nums.rend());
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum < target) return -1;
        
        vector<int> startPath;
        dfs(0, startPath, 0, nums, target);
        return maxLen;
    }
    private:
    int maxLen = -1;
    void dfs(int start, vector<int>& currPath, int currSum, vector<int>& options, int target)
    {
        if (currSum == target) {
            maxLen = max(maxLen, (int)currPath.size());
            return;
        }

        for (int i=start; i<options.size(); i++) {
            if (currSum + options[i] > target) continue;

            currPath.push_back(options[i]);
            dfs(i+1, currPath, currSum+options[i], options, target);
            currPath.pop_back();
        }
    }
};