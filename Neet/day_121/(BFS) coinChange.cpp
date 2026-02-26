class Solution 
{
    public:
    // return the minimum number of coins to make up amount
    int coinChange(vector<int>& coins, int amount) 
    {
        if (amount == 0) return 0;

        queue<int> q;
        unordered_set<int> visited;
        visited.insert(0);
        q.push(0);

        int numOfCoins = 0;
        while (!q.empty()) {
            int size = q.size();

            for (int i=0; i<size; i++) {
                int currAmt = q.front();
                q.pop();

                if (currAmt == amount) return numOfCoins;
                for (int coin : coins) {
                    long long nextAmt = (long long)currAmt + (long long)coin;
                    if (nextAmt > amount) continue;
                    if (visited.count(nextAmt)) continue;

                    q.push(nextAmt);
                    visited.insert(nextAmt);
                }
            }
            numOfCoins++;
        }
        return -1;
    }
};