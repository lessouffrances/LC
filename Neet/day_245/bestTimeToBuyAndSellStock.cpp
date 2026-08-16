class Solution 
{
    public:
    int maxProfit(vector<int>& prices) 
    {
        if (prices.empty()) return 0;
        int n = prices.size();

        int buy = prices[0];
        int maxProfit = 0;
        for (int i=1; i<n; i++) {
            maxProfit = max(maxProfit, max(0, prices[i]-buy));
            buy = min(buy, prices[i]);
        }
        return maxProfit;
    }
};