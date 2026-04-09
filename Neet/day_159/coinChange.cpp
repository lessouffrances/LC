




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

                for (int deno : coins) {
                    long long nextAmount = (long long)currAmount + (long long)deno;
                    if (nextAmount > amount || visited.count(nextAmount)) continue;
                    visited.insert(nextAmount);
                    q.push(nextAmount);
                }
            }
            numOfCoins++;
        }
        return -1;
    }
};