class Solution 
{
    public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) 
    {
        // calculate the initial sum
        long long initialSum = (long long)(1+n) * n /2;
        long long diff = initialSum - target;
        if (target > initialSum || target < -initialSum || diff % 2 != 0) {
            return {};
        }

        vector<bool> negated(n+1, false);

        for (int i=n; i>=1; i--) {
            if (2 * i <= diff) {
                negated[i] = true;
                diff -= 2 * i;
            }
        }

        vector<int> res;
        for (int i=1; i<=n; i++) {
            if (negated[i] ==  true) {
                res.push_back(-i);
            } else {
                res.push_back(i);
            }
        }
        
        sort(res.begin(), res.end());
        return res;
    }
};