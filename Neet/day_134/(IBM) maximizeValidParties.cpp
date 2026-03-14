#include <algorithm>
#include <vector>

int findMaxWatchParties(vector<int>& engagementScores, int minWatchPartyScore) 
{
    sort(engagementScores.rbegin(), engagementScores.rend());
    int n = engagementScores.size();

    // dp[i] = max parties using first i people (0-indexed: people 0..i-1)
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) 
    {
        // option 1: skip person i, don't group them
        dp[i] = dp[i - 1];

        // option 2: form a party ending at index i-1 (the smallest score so far)
        // try all group sizes: party uses people [i-size .. i-1]
        // since sorted descending, min score of group = engagementScores[i-1]
        // THIS is always the minimum because it's the rightmost (smallest) element
        for (int size = 1; size <= i; size++) 
        {
            // group spans indices [i-size .. i-1]
            // minimum is always engagementScores[i-1] since array is sorted desc
            int minScore = engagementScores[i - 1];
            long long score = (long long)size * minScore;

            if (score >= minWatchPartyScore) 
            {
                dp[i] = max(dp[i], dp[i - size] + 1);
                // since larger size only keeps same minScore but increases product,
                // all larger sizes are also valid — but we want max parties,
                // so take the SMALLEST valid size to leave more people for other parties
                break;
            }
        }
    }

    return dp[n];
}