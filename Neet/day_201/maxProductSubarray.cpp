class Solution 
{
    public:
    int maxProduct(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        int currMax = nums[0];
        int currMin = nums[0];
        int res = nums[0];
        for (int i=1; i<n; i++) {
            int tempMax = currMax;
            currMax = max( {nums[i], currMin*nums[i], tempMax*nums[i]} );
            currMin = min( {nums[i], currMin*nums[i], tempMax*nums[i]} );
            res = max(currMax, res);
        }
        return res;
    }
};