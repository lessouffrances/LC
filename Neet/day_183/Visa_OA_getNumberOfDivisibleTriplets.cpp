// Question 1 — Divisible Triplets
// Given an integer array nums and an integer divisor, 
// find the total number of triplets (nums[i], nums[j], nums[k]) 
// where i < j < k such that (nums[i] + nums[j] + nums[k]) is divisible by divisor.

// Function Description:
// int countTriplets(int[] nums, int divisor)
// Returns: int — the total number of valid triplets.
// Example:
// nums = [1, 2, 3, 4, 5], divisor = 3
// Output: 4

// Constraints:
// 3 <= n <= 10^3
// 1 <= nums[i] <= 10^9
// 2 <= divisor <= 10^6

class Solution 
{
    int countTriplets(vector<int> nums, int divisor)
    {
        if (nums.empty()) return 0;
        int n = nums.size();
        int count = 0;

        for (int i=0; i<n-2; i++) {
            for (int j=i+1; j<n-1; j++) {
                for (int k=j+1; k<n; k++) {
                    if ( ((long long)nums[i]+nums[j]+nums[k]) % divisor == 0) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};