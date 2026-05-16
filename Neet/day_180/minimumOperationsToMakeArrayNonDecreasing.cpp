// [3,3,3,1]
// res = 0+1+2 = 3

// [3,3,3,2]
// res = 0+1+1 = 2
// [3,3,2,1]

class Solution 
{
    public:
    long long minOperations(vector<int>& nums) {
        if (nums.empty()) return 0;

        long long res = 0;
        int n = nums.size();
        for (int i = n-2; i >= 0; i--) {
            if (nums[i] > nums[i+1]) {
                res += nums[i] - nums[i+1];
            }
        }
        
        return res;
    }
};