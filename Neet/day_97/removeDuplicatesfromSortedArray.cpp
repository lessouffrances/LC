








//  left = 2
//  right = 2;
//                              r
// nums = [0,1,2,3,4,2,2,3,3,4]
//                 l

class Solution 
{
    public:
    int removeDuplicates(vector<int>& nums) 
    {

        if (nums.empty()) return 0;
        int n = nums.size();
        if (n == 1) return 1;

        int left = 0; 
        for (int right=0; right<n; right++) { 
            if (right>0 && nums[right] == nums[right-1]) continue;

            nums[left] = nums[right];
            left++;
        }
        return left;
    }
};