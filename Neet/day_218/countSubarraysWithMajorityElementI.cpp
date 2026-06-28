class Solution 
{
    public:
    int countMajoritySubarrays(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int res = 0;
        for (int start=0; start<n; start++) {
            int count = 0;
            for (int end=start; end<n; end++) {
                count += (nums[end] == target) ? 1 : -1;
                if (count > 0) res++;
            }
        }
        return res;
    }
};