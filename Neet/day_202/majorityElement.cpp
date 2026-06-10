class Solution 
{
    public:
    int majorityElement(vector<int>& nums) 
    {
        if (nums.empty()) return 0;

        int candidate = nums[0];
        int count = 1;
        for (int i=1; i<nums.size(); i++) {
            count += (nums[i] == candidate) ? 1 : -1;
            if (count == 0) {
                count = 1;
                candidate = nums[i];
            }
        }
        return candidate;
    }
};