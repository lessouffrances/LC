class Solution 
{
    public:
    int coinChange(vector<int>& coins, int amount) 
    {
        if (coins.empty()) return 0;

        queue<int> q;
        q.push(0);
        unordered_set<int> visited;
        visited.insert(0);

        int numOfCoins = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto currAmount = q.front();
                q.pop();
                
                if (currAmount == amount) return numOfCoins;
                for (int coin : coins) {
                    if (coin > amount - currAmount) continue;
                    int nextAmount = coin + currAmount;
                    if (visited.count(nextAmount)) continue;
                    q.push(nextAmount);
                    visited.insert(nextAmount);
                }
            }
            numOfCoins++;
        }   

        return -1;
    }
};