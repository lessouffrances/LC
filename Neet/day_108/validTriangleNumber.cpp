class Solution 
{
    public:
    int triangleNumber(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;

        for (int i=n-1; i>=2; i--) {
            int side1 = nums[i];

            int left = 0, right = i-1;
            while (left < right) {
                if (nums[left] + nums[right] > side1) {
                    count += (right - left);
                    right--;
                } else {
                    left++;
                }
            }
        }
        return count;
    }
};