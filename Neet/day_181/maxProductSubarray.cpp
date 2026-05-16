



class Solution 
{
    public:
    int maxProduct(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        int currMin = nums[0];
        int currMax = nums[0];
        int maxProduct = nums[0];
        for (int i=1; i<n; i++) {
            int tempMin = currMin;
            currMin = min( {nums[i], nums[i]*currMax, nums[i]*tempMin} );
            currMax = max( {nums[i], nums[i]*currMax, nums[i]*tempMin} );
            maxProduct = max(maxProduct, currMax);
        }
        return maxProduct;
    }
};