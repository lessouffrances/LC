




// nums = [0,1,2,2,3,0,4,2], val = 2

// Time: O(N)
// Space: O(1)
class Solution 
{
    public:
    int removeElement(vector<int>& nums, int val) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        int write = 0;
        for (int read=0; read<n; read++) {
            if (nums[read] == val) continue;
            nums[write] = nums[read];
            write++;
        }
        return write;
    }
};