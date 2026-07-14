// Maximum Collection Jump
// You are given an array nums of length n containing both positive and negative integers. 
// Starting at index 0, you want to reach index n-1 while collecting numbers along the way.
// At each position i, you can jump to:

// i+1 or i-1 (adjacent positions)
// i+p where p is any prime number ending in digit 3 (e.g. 3, 13, 23, 43...)

// You may only land on valid indices [0, n-1]. Each time you land on a position, you collect nums[i].
// Return the maximum sum you can collect by the time you reach index n-1.
// Example:
// Input:  nums = [0, -20, 80, -40, -10]
// Output: 10
// Explanation: 0 → 1 → 2 → 3 → 4
//              0 + (-20) + 80 + (-40) + (-10) = 10
// Constraints:
// 1 <= n <= 10^4
// -10^4 <= nums[i] <= 10^4

class Solution 
{
    vector<int> primesEndingIn3(int n) 
    {
        // sieve of eratosthenes
        vector<bool> sieve(n+1, true);
        // we all know that the smallest prime is 2
        sieve[0] = sieve[1] = false;
        for (int i=2; i*i<=n; i++) {
            if (sieve[i]) {
                for (int j=i*i; j<=n; j+=i) {
                    sieve[j] = false;
                }
            }
        }
    
        vector<int> res;
        for (int i=3; i<=n; i++) {
            if (sieve[i] && i % 10 == 3) res.push_back(i);
        }
        return res;
    }

    // subproblem: up until dp[i], what's the maximized value?
    // look back,
    // dp[i-1]: max(dp[i-1]+nums[i], dp[i])
    // dp[i-p]: max(dp[i-p]+nums[i], dp[i])
    int maxCollect(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> primeJumps = primesEndingIn3(n);
        vector<int> dp(n, INT_MIN);
        dp[0] = nums[0];
        
        for (int i = 1; i < n; i++) {
            // first option, the adjacent ones
            if (dp[i-1] != INT_MIN) {
                dp[i] = max(dp[i], dp[i-1] + nums[i]);
            }
            // second option, the prime ones
            for (int p : primeJumps) {
                if (i-p >= 0 && dp[i-p] != INT_MIN)
                dp[i] = max(dp[i], dp[i-p] + nums[i]);
            }    
        }
        return dp[n-1];
    }
};
