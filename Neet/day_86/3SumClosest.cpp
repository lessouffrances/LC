class Solution 
{
    public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());

        int res = accumulate(nums.begin(), nums.begin()+3, 0);
        int n = nums.size();

        for (int start=0; start<n; start++) {
            int l = start+1;
            int r = nums.size()-1;

            while (l < r) {
                int currSum = nums[start] + nums[l] + nums[r];
                if (abs(currSum-target) < abs(res-target)) {
                    res = currSum;
                }

                if (currSum < target) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return res;
    }
};