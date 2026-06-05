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
            count += (nums[i] == candidate) ? 1 : -1;
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            }
        }
        return candidate;
    }
};