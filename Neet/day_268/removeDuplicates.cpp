class Solution 
{
    public:
    int removeDuplicates(vector<int>& nums) 
    {
        int n = nums.size();

        int write = 1;
        for (int read=1; read<n; read++) {
            if (nums[read] == nums[read-1]) continue;
            nums[write] = nums[read];
            write++;
        }
        return write;
    }
};