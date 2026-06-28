class Solution 
{
    public:
    int sortPermutation(vector<int>& nums) 
    {
        int n = nums.size();
        bool sorted = true;
        int k = (1 << 20)-1;
        
        for (int i=0; i<n; i++) {
            if (nums[i] != i) {
                sorted = false;
                k &= nums[i];
            }
        }
        return sorted ? 0 : k;
    }
};