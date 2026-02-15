class Solution 
{
    public:
    vector<int> constructTransformedArray(vector<int>& nums) 
    {
        if (nums.empty()) return {};

        int n = nums.size();
        vector<int> res(n);

        for (int i=0; i<n; i++) {
            if (nums[i] > 0) {
                int endIdx = (i + nums[i]) % n;
                res[i] = nums[endIdx];
            } else if (nums[i] < 0) {
                int endIdx = (i - abs(nums[i]) % n + n) % n;
                res[i] = nums[endIdx];
            } else {
                res[i] = nums[i];
            }
        }
        return res;
    }
};