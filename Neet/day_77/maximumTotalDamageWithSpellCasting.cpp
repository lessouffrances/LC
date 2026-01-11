class Solution {
    public:
    long long maximumTotalDamage(vector<int>& power) 
    {
        if (power.empty()) return 0;

        map<int, long long> freq;
        for (int p : power) {
            freq[p]++;
        }

        vector<pair<int, long long>> damage;
        for (auto& [p, count] : freq) {
            damage.push_back( {p, (long long) p * count} );
        }

        int n = damage.size();
        if (n == 1) return damage[0].second;

        vector<long long> dp(n);
        dp[0] = damage[0].second;
        for (int i=1; i<n ; i++) {
            long long skip = dp[i-1];

            long long take = damage[i].second;
            
            // find the last index we can take
            int j = i - 1;
            while (j >= 0 && damage[j].first >= damage[i].first - 2) {
                j--;
            }

            if (j >= 0) {
                take += dp[j];
            }

            dp[i] = max(skip, take);
        }
        return dp[n-1];
    }
};