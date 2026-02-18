



class Solution 
{
    public:
    vector<int> constructTransformedArray(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        int n = nums.size();

        vector<int>res(n);

        for (int i=0; i<n; i++) {
            if (nums[i] < 0) {
                int idx = (i - abs(nums[i]) % n + n) % n;
                res[i] = nums[idx];
            } else if (nums[i] > 0) {
                int idx  = (i + nums[i]) % n;
                res[i] = nums[idx];
            } else {
                res[i] = nums[i];
            }
        }
        return res;
    }
};