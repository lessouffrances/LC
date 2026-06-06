class Solution 
{
    public:
    int maxProfit(vector<int>& prices) 
    {
        if (prices.empty()) return 0;

        int n = prices.size();
        int buy = prices[0];
        int profit = 0;
        for (int i=1; i<n; i++) {
            profit = max(profit, max(0, prices[i]-buy));
            buy = min(buy, prices[i]);
        }
        return profit;
    }
};