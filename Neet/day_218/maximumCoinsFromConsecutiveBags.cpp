// coins = [[8,10,1],[1,3,2],[5,6,4]], k = 4
// coins = [ [1,3,2],[5,6,4], [8,10,1] ]
class Solution 
{
    public:
    long long maximumCoins(vector<vector<int>>& coins, int k) 
    {
        sort(coins.begin(), coins.end());
        int n = coins.size();

        // prefixSum of coins
        vector<long long> prefixSum(n+1, 0);
        for (int i=0; i<n; i++) {
            prefixSum[i+1] = prefixSum[i]+((coins[i][1]-coins[i][0]+1)*coins[i][2])
        }

        long long maxCoins = 0;
        // try placing window starting at each interval's left endpoint
        // and each interval's right endpoint - k + 1




    }


    private:
    long long getCoins(vector<vector<int>>& coins, vector<long long>& prefixSum, long long left, long long right)
    {
        int n = coins.size();
        
    }
};