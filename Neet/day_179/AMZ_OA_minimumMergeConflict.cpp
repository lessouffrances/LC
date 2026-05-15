// Problem Statement: Minimum Merge Conflicts
// Context:
// At Amazon, developers want to merge primary and secondary source control branches into a unified branch while preserving the order of commits from each branch. Each character of a branch represents a commit's priority, with lower alphabetical order indicating higher priority.
// A conflict occurs when, in the merged branch, a commit with lower priority is placed before a commit with higher priority. Your task is to find the minimum number of conflicts in any valid merge of primary and secondary branches.

// Example:
// primary = "zc"
// secondary = "d"

// There are three possible merge arrangements:
// "zcd" → 2 merge conflicts ('z' being lower priority is placed before higher priority commits 'c' and 'd')
// "zdc" → 3 merge conflicts
// "dzc" → 2 merge conflicts

// The minimum number of merge conflicts possible is 2.

// Function Description:
// The function getMinimumConflicts takes the following input:

// string primary: the commit sequence of the primary branch
// string secondary: the commit sequence of the secondary branch

// Returns:
// int: the minimum number of conflicts after a valid merge

// Constraints:
// 1 ≤ |primary|, |secondary| ≤ 1000
// primary and secondary consist of lowercase English letters only.

// Sample Case 0:
// Input: primary = "dae", secondary = "add"
// Output: 1

// Simplify as:
// Minimum Merge Conflicts
// Given two strings primary and secondary representing commit sequences, merge them into one string preserving the relative order of each. A conflict occurs when a lower-priority character (higher alphabetical order) appears before a higher-priority one in the merged result. Return the minimum number of conflicts across all valid merges.
// Example:
// primary="zc", secondary="d"
// Best merge: "zcd" or "dzc" → 2 conflicts
// Output: 2
// Constraints: 1 ≤ |primary|, |secondary| ≤ 1000, lowercase letters only.

class Solution
{
    public:
    int getMinimumConflicts(const string& primary, const string& secondary) 
    {
        int m = primary.length();
        int n = secondary.length();

        auto primaryLessThan = precomputeLessThan(primary);
        auto secondaryLessThan = precomputeLessThan(secondary);

        // dp[i][j] = min conflicts when primary[0..i-1] and secondary[0..j-1]
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        // base case
        dp[0][0] = 0;

        for (int i=0; i<=m; i++) {
            for (int j=0; j<=n; j++) {
                if (dp[i][j] == INT_MAX) continue;

                int curr = dp[i][j];

                // Option 1: place primary[i] next
                if (i < m) {
                    int ch = primary[i]-'a';
                    int conflicts = primaryLessThan[i+1][ch] + secondaryLessThan[j][ch];
                    dp[i+1][j] = min(dp[i+1][j], curr+conflicts);
                }

                // Option 2: place secondary[j] next
                if (j < n) {
                    int ch = secondary[j]-'a';
                    // Remaining: primary[i..m-1] and secondary[j+1..n-1]
                    int conflicts = primaryLessThan[i][ch] + secondaryLessThan[j+1][ch];
                    dp[i][j+1] = min(dp[i][j+1], curr+conflicts);
                }
            }
        }
        return dp[m][n];
    }

    private:
    // buildLessThan[i][c] = # chars < c in s[i..n-1] 
    vector<vector<int>> precomputeLessThan(const string& s)
    {
        int n = s.length();
        // (n+1) * 26 matrix
        vector<vector<int>> lessThan(n+1, vector<int>(26, 0));

        for (int i=n-1; i>=0; i--) {
            lessThan[i] = lessThan[i+1];
            int ch = s[i]-'a';
            for (int k=ch+1; k<26; k++) {
                lessThan[i][k]++;
            }
        }
        return lessThan;
    }
};