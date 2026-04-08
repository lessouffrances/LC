class Solution 
{
    public:
    int coinChange(vector<int>& coins, int amount) 
    {
        unordered_set<int> visited;
        queue<int> q;
        visited.insert(0);
        q.push(0);
        int numOfCoins = 0;

        while (!q.empty()) {
            int size = q.size();

            for (int i=0; i<size; i++) {
                auto currAmount = q.front();
                q.pop();

                if (currAmount == amount) return numOfCoins;

                for (int coin : coins) {
                    long long nextSum = (long long) coin + (long long) currAmount;
                    if (nextSum > amount || visited.count(nextSum)) continue;

                    visited.insert(nextSum);
                    q.push(nextSum);
                }
            }
            numOfCoins++;
        }
        return -1;
    }
};