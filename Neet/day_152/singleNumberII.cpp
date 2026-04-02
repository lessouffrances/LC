

// nums = [0,1,0,1,0,1,99]
// [0,0,0,1,1,1,2,99,99,99]

class Solution 
{
    public:
    int singleNumber(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        for (int i=0; i<n-1; i+=3) {
            if (nums[i] == nums[i+1]) continue;
            return nums[i];
        }
        return nums[n-1];
    }
};