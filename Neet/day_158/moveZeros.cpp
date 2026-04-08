

//                r
// nums = [1,3,12,0,0]
//                w
class Solution 
{
    public:
    void moveZeroes(vector<int>& nums) 
    {
        if (nums.empty()) return;
        int n = nums.size();

        int write = 0;
        for (int read=0; read<n; read++) {
            if (nums[read] != 0) {
                nums[write] = nums[read];
                write++;
            }
        }

        // let the remaining be all 0
        while (write < n) {
            nums[write] = 0;
            write++;
        }
    }
};