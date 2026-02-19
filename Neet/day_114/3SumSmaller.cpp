


class Solution 
{
    public:
    int threeSumSmaller(vector<int>& nums, int target) 
    {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int count = 0;

        for (int i=n-1; i>=2; i--) {
            int diff = target-nums[i];
            int left = 0, right = i-1;

            // want to find sum < diff
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum >= diff) {
                    right--;
                } else {
                    count += (right-left);
                    left++;
                }
            }
        }
        return count;
    }
};