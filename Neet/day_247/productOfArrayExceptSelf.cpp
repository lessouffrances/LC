
// 
// nums = [1,2,3,4]
class Solution 
{
    public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        if (nums.empty()) return {};

        int n = nums.size();
        vector<int> prefixProduct(n, 1);
        int currProduct =1;
        for (int i=1; i<n; i++) {
            currProduct *= nums[i-1];
            prefixProduct[i] = currProduct;
        }

        vector<int> suffixProduct(n, 1);
        currProduct = 1;
        for (int i=n-2; i>=0; i--) {
            currProduct *= nums[i+1];
            suffixProduct[i] = currProduct;
        }

        vector<int> res;
        for (int i=0; i<n; i++) {
            int prefix = prefixProduct[i];
            int suffix = suffixProduct[i];
            res.push_back(prefix * suffix);
        }
        return res;
    }
};