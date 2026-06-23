class Solution 
{
    public:
    int maxProfit(vector<int>& prices) 
    {
        if (prices.empty()) return 0;
        int n = prices.size();

        int left = 0;
        int totalProfit = 0;
        for (int right=0; right<n; right++) {
            if (prices[right] > prices[left]) {
                totalProfit += (prices[right]-prices[left]);
                left = right;
            } else {
                left = right;
            }
        }

        return totalProfit;
    }
};