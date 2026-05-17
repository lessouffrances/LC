// T1 — Maximum Even Sum Subset
// Problem: Given n integers, select any subset (including empty) 
// such that the sum is even and as large as possible.

// Approach: Compute the sum S of all positive numbers. 
// If S is even, return it directly. 
// If S is odd, we need to make it even by either:
// Subtracting the smallest positive odd number, or
// Adding the largest negative odd number 
// Take whichever gives the larger result.

class Solution 
{
    public:
    long long maxEvenSum(vector<int>& nums) 
    {
        if (nums.empty()) return 0;

        long long totalPosSum = 0;
        int minPosOdd = INT_MAX;
        int maxNegOdd = INT_MIN;

        for (int num : nums) {
            if (num > 0) {
                totalPosSum += num;
                if (num % 2 != 0) {
                    minPosOdd = min(minPosOdd, num);
                }
            } else {
                if (num % 2 != 0) {
                    maxNegOdd = max(maxNegOdd, num);
                }
            }
        }

        if (totalPosSum % 2 == 0) return totalPosSum;

        long long best = LLONG_MIN;
        if (minPosOdd != INT_MAX) best = max(best, S-minPosOdd);
        if (maxNegOdd != INT_MIN) best = max(best, S+maxNegOdd);
        return max(best, 0LL);
    }
};