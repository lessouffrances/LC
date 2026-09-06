class Solution 
{
    public:
    int lengthOfLIS(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();
        unordered_map<int, int> lookUp;
        lookUp[0] = 1; //seed
        int res = 1;

        for (int i=1; i<n; i++) {
            lookUp[i] = 1;
            for (int j=0; j<i; j++) {
                if (lookUp.count(j) && nums[j] < nums[i]) {
                    lookUp[i] = max(lookUp[i], 1+lookUp[j]);
                    res = max(res, lookUp[i]);
                }
            }
        }
        return res;
    }
};