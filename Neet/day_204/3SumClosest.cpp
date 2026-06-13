class Solution 
{
    public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = nums[0]+nums[1]+nums[2];

        for (int i=0; i<n-2; i++) {
            int left = i+1, right = n-1;
            while (left < right) {
                int threeSum = nums[i]+nums[left]+nums[right];

                if (abs(threeSum-target) < abs(res-target)) {
                    res = threeSum;
                }

                if (threeSum > target) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return res;
    }
};