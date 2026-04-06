



// Time: O(N)
// Space: O(N)

class Solution 
{
    public:
    vector<int> runningSum(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        int n = nums.size();

        vector<int>res;
        int currSum = 0;
        for (int i=0; i<n; i++) {
            currSum += nums[i];
            res.push_back(currSum);
        }
        return res;
    }
};