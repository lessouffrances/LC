class Solution 
{
    public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        // need to build the prefix product and suffix product
        vector<int> prefix(n, 1);
        int currProduct = 1;
        for (int i=1; i<n; i++) {
            currProduct *= nums[i-1];
            prefix[i] = currProduct;
        }

        vector<int> suffix(n, 1);
        currProduct = 1;
        for (int i=n-2; i>=0; i--) {
            currProduct *= nums[i+1];
            suffix[i] = currProduct;
        }

        vector<int> res;
        for (int i=0; i<n; i++) {
            res.push_back(prefix[i] * suffix[i]);
        }
        return res;
    }
};