


// prices = [7,1,5,3,6,4]
// Time: O(N)
// Space: O(1)
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
            int profit = max(prices[i]-buy, 0);
            maxProfit = max(maxProfit, profit);
            buy = min(buy, prices[i]);
        }
        return maxProfit;
    }
};