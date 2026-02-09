




class Solution 
{
    public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) 
    {
        long long initialSum = (long long)(1+n) * n / 2;
        long long diff = initialSum - target;

        if (target < -initialSum || target > initialSum || diff % 2 != 0) return {};

        vector<bool>negated(n+1, false);
        for (int i=n; i>=1; i--) {
            if (2 * i <= diff) {
                diff -= 2 * i;
                negated[i] = true;
            }
        }

        vector<int> res;
        for (int i=1; i<=n; i++) {
            if (negated[i] == true) {
                res.push_back(-i);
            } else {
                res.push_back(i);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};