class Solution 
{
    public:
    int change(int amount, vector<int>& coins) 
    {
        if (coins.empty()) return 0;
        return dfs(0, amount, coins);
    }

    private:
    map<pair<int, int>, int> memo;

    int dfs(int start, int remaining, vector<int>& coins)
    {
        if (remaining == 0) return 1;
        if (remaining < 0 || start == coins.size()) return 0;

        if (memo.count( {start, remaining} )) return memo[ {start, remaining} ];

        int res = 0;
        for (int i=start; i<coins.size(); i++) {
            res += dfs(i, remaining-coins[i], coins);
        }

        memo[ {start, remaining} ] = res;
        return res;
    }
};