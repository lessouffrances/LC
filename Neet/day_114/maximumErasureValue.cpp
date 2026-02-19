





// nums = [5, 2, 1, 2, 5,2 ,1 ,2, 5]
//        l,r

// find the max sum of subarray does not contain duplicate chars
class Solution 
{
    public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();
        int maxSum = 0;
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int>windowCounter(maxi+1, 0);

        int left = 0;
        for (int right=0; right<n; right++) {
            windowCounter[nums[right]]++;

            while (windowCounter[nums[right]] == 2) {
                windowCounter[nums[left]]--;
                left++;
            }

            maxSum = max(maxSum, accumulate(nums.begin()+left, nums.begin()+right+1, 0));
        }
        return maxSum;
    }
};