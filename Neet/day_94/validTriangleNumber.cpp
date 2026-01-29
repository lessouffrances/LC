class Solution 
{
    public:
    int triangleNumber(vector<int>& nums) 
    {
        if (nums.empty() || nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;

        // 3 sum technqiue
        // fixed the largest side
        for (int k=n-1; k>=2; k--) {
            int left = 0, right = k-1;

            while (left < right) {
                if (nums[left] + nums[right] > nums[k]) {
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