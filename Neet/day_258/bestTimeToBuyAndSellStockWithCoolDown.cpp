class Solution 
{
    public:
    int maxProfit(vector<int>& prices) 
    {
        return dfs(0, true, prices);
    }

    private:
    map<pair<int, bool>, int> memo;
    int dfs(int i, bool canBuy, vector<int>& prices)
    {
        if (i >= prices.size()) return 0;

        if (memo.count( {i, canBuy} )) return memo[ {i, canBuy} ];
        if (canBuy) {
            int cool = dfs(i+1, canBuy, prices);
            int buy = dfs(i+1, !canBuy, prices) - prices[i];
            memo[ {i, canBuy} ] = max(cool, buy); 
        } else {
            int sell = dfs(i+2, !canBuy, prices) + prices[i];
            int cool = dfs(i+1, canBuy, prices);
            memo[ {i, canBuy} ] = max(cool, sell); 
        }
        return memo[ {i, canBuy} ];
    }
};