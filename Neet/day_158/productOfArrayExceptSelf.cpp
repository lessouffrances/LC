



class Solution 
{
    public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        int n = nums.size();

        // prefixProduct;
        vector<int> prefixProduct(n);
        prefixProduct[0] = 1;
        int currProduct = 1;
        for (int i=1; i<n; i++) {
            currProduct *= nums[i-1];
            prefixProduct[i] = currProduct;
        }

        // suffixProduct;
        vector<int> suffixProduct(n);
        suffixProduct[n-1] = 1;
        currProduct = 1;
        for (int i=n-2; i>=0; i--) {
            currProduct *= nums[i+1];
            suffixProduct[i] = currProduct;
        }

        vector<int> res;
        for (int i=0; i<n; i++) {
            res.push_back(prefixProduct[i] * suffixProduct[i]);
        }
        return res;
    }
};