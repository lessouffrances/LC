class Solution 
{
    public:
    int maxProfit(vector<int>& prices) 
    {
        if (prices.empty()) return -1;

        int n = prices.size();
        int maxProfit = 0;
        int lowest = INT_MAX;
        for (int i=0; i<n; i++) {
            if (prices[i] < lowest) {
                lowest = prices[i];
            }
            maxProfit = max(maxProfit, prices[i]-lowest);
        }
        return maxProfit;
    }
};