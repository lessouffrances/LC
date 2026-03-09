

// Time: O(N log N)
// Space: O(N)

class Solution 
{
    public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) 
    {
        // the starting point
        long long initialSum = (long long)(1+n) * (n) / 2;
        
        // In order to achieve target, what is the diff
        // We need to negate elements to reach the diff
        long long diff = initialSum - target;

        // when we negate an element in the array,
        // the contribution is always -2 * nums[i] 
        if (target < -initialSum || target > initialSum || diff % 2 != 0) return {};

        // a tracker to record which num to negate
        vector<bool> negated(n+1, false); 
        
        for (int i=n; i>=0; i--) {
            if (2 * i <= diff) {
                negated[i] = true;
                diff -= 2 * i;
                if (diff == 0) break;
            }
        }

        // build res
        vector<int> res;
        for (int i=1; i<=n; i++) {
            res.push_back(negated[i] ? -i : i);
        }

        // sort for lexi smaller first
        sort(res.begin(), res.end());
        return res;
    }
};
        