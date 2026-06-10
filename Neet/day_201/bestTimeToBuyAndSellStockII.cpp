
// prices = [7,1,5,3,6,4], exp = 7
//               l
//               r
class Solution 
{
    public:
    int maxProfit(vector<int>& prices) 
    {
        if (prices.empty()) return 0;
        int n = prices.size();
        int totalProfit = 0;
        int left = 0;
        
        for (int right=0; right<n; right++) {
            if (prices[right] > prices[left]) {
                totalProfit += prices[right]-prices[left];
                left = right;
            } else {
                left = right;
            }
        }
        return totalProfit;
    }
};