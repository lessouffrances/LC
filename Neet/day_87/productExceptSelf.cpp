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

        vector<int>prefix(n);
        prefix[0] = 1;
        for (int i=1; i<n; i++) {
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        vector<int>suffix(n);
        suffix[n-1] = 1;
        for (int i=n-2; i>=0; i--) {
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        vector<int>res;
        for (int i=0; i<n; i++) {
            res.push_back(prefix[i] * suffix[i]);
        }

        return res;
    }
};
