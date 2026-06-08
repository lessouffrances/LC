// nums = [3,2,1,0,4]
// the condition to reach i: 
// look for the previous pos that's T, if from that pos, you can jump to this pos,
// then this pos is T

// dp[0] = T, base case
// dp =   [T,T,T,T,F]




class Solution 
{
    public:
    bool canJump(vector<int>& nums) 
    {
        int n = nums.size();
        int goal = n-1;
        for (int i=n-1; i>=0; i--) {
            if (i+nums[i] >= goal) {
                goal = i;
            }
        }
        return goal == 0;
    }
};