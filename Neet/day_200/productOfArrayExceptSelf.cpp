

// nums =   [1,2,3,4]
// prefix   [1,1,2,6]
// suffix   [24,12,4,1]
class Solution 
{
    public:

    vector<int> productExceptSelf(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        int n = nums.size();

        vector<int> prefixProduct(n, 1);
        vector<int> suffixProduct(n, 1);

        // build prefixProduct
        for (int i=1; i<n; i++) {
            prefixProduct[i] = prefixProduct[i-1]*nums[i-1];
        }

        // build suffixProduct
        for (int i=n-2; i>=0; i--) {
            suffixProduct[i] = suffixProduct[i+1]*nums[i+1];
        }

        vector<int> res;
        for (int i=0; i<n; i++) {
            res.push_back(prefixProduct[i] * suffixProduct[i]);
        }
        return res;
    }
};