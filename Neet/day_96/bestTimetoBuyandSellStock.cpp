class Solution {
    public:
        int maxProfit(vector<int>& prices) 
        {
            if (prices.empty()) return 0;
            int n = prices.size();

            int buy = prices[0];
            int maxProfit = 0;
            for (int i=1; i<n; i++) {
                if (prices[i] > buy) {
                    maxProfit = max(maxProfit, prices[i]-buy);
                }

                buy = min(buy, prices[i]);
            }
            
            return maxProfit;
        }
    };