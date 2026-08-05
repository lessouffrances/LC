class Solution 
{
    public:
    int majorityElement(vector<int>& nums) 
    {
        if (nums.empty()) return 0;

        int n = nums.size();
        int count = 1;
        int candidate = nums[0];
        for (int i=1; i<n; i++) {
            count += (candidate == nums[i]) ? 1 : -1;
            if (count == 0) {
                count = 1;
                candidate = nums[i];
            }
        }
        return candidate;
    }
};