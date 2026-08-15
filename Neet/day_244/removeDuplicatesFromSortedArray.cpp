class Solution 
{
    public:
    int removeDuplicates(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        int write = 0;
        for (int read=0; read<n; read++) {
            if (read+1 < n && nums[read] == nums[read+1]) continue;
            nums[write] = nums[read];
            write++;
        }
        return write;
    }
};