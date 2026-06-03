class Solution 
{
    public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) 
    {
        if (rides.empty()) return 0;

        sort(rides.begin(), rides.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });

        int m = rides.size();
        vector<long long> dp(m+1, 0);

        for (int i=1; i<m+1; i++) {
            // option 1: take this passenger
            long long earning = rides[i-1][1] - rides[i-1][0] + rides[i-1][2];
            // binarySearch on previous compatible ride, where end <= start
            int left = 0, right = i-1;

            while (left < right) {
                int mid = left + (right - left + 1) / 2;
                if (rides[mid-1][1] <= rides[i-1][0]) {
                    left = mid;
                } else {
                    right = mid-1;
                }
            }

            long long take = earning + dp[left];

            // option 2: skip
            dp[i] = max(dp[i-1], take);
        }
        return dp[m];
    }
};