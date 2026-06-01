class Solution 
{
    public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) 
    {
        // sort the trips by the end point
        sort(rides.begin(), rides.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });

        int m = rides.size();
        vector<long long> dp(m+1, 0); // dp[i] = max earnings using first i rides
        
        for (int i=1; i<=m; i++) {
            int start = rides[i-1][0];
            int end = rides[i-1][1];
            int tip = rides[i-1][2];
            long long earn = end - start + tip;

            int lo = 0, hi = i-1;
            // find the last ride that ends <= curr start
            while (lo < hi) {
                int mid = lo + (hi-lo) / 2;
                if (rides[mid-1][1] <= start) {
                    lo = mid;
                } else {
                    hi = mid-1;
                }
            }

            dp[i] = max(dp[i-1], dp[lo] + earn);
        }
        return dp[m];
    }
};