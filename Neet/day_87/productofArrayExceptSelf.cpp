// nums = {1, 2, 3, 4}
// prefix = {1, 1, 2, 6}
// suffix = {24, 12, 4, 1}
class Solution 
{
    public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        int n = nums.size();

        vector<int> res(n);
        int prefix = 1, suffix = 1;

        for (int i=0; i<n; i++) {
            res[i] = prefix;
            prefix *= nums[i];
        }
        for (int j=n-1; j>=0; j--) {
            res[j] *= suffix;
            suffix *= nums[j];
        }
        return res;
    }
};
