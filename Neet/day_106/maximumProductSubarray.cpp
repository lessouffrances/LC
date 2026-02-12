







class Solution 
{
    public:
    int maxProduct(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        int currMin = nums[0];
        int currMax = nums[0];
        int res = nums[0];
        for (int i=1; i<n; i++) {
            int tempMax = currMax;
            currMax = max( {nums[i], tempMax * nums[i], currMin * nums[i]} );
            currMin = min( {nums[i], tempMax * nums[i], currMin * nums[i]} );

            res = max(res, currMax);
        }
        
        return res; 
    }
};