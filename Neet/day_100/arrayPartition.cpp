









class Solution 
{
    public:
    int arrayPairSum(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int sum = 0;
        for (int i=0; i<n; i+=2) {
            sum += nums[i];
        }
        
        return sum;
    }
};