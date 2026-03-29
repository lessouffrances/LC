
//         w
// nums = [0,0,1,1,1,2,2,3,3,4]
//           r

// Time: O(N)
// Space: O(1)
class Solution 
{
    public:
    int removeDuplicates(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        int write = 1;
        for (int read=1; read<n; read++) {
            // simply ignore the adj duplicates
            if (nums[read] == nums[read-1]) continue;

            nums[write] = nums[read];
            write++;
        }
        return write;
    }
};