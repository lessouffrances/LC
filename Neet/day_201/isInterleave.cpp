class Solution 
{
    public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        if (s1.length() + s2.length() != s3.length()) return false;
        return dfs(0, s1, 0, s2, s3);
    }
    private:
    map<pair<int, int>, bool> memo;
    bool dfs(int i, string s1, int j, string s2, string s3)
    {
        if (i == s1.length() && j == s2.length()) {
            memo[ {i, j} ] = true;
            return true;
        }

        if (memo.count( {i, j} )) return memo[ {i, j} ];

        if (i < s1.length() && s1[i] == s3[i+j] && dfs(i+1, s1, j, s2, s3)) return true;
        if (j < s2.length() && s2[j] == s3[i+j] && dfs(i, s1, j+1, s2, s3)) return true;

        memo[ {i, j} ] = false;
        return false;
    }

};