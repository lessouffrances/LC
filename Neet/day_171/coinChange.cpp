// T: O(n * amount)
// S: O(amount) for the queue

class Solution 
{
    public:
    int coinChange(vector<int>& coins, int amount) 
    {
        if (coins.empty()) return -1;
        
        queue<int> q;
        q.push(0);
        unordered_set<int> visited;
        visited.insert(0);

        int numOfCoins = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                int currAmount = q.front();
                q.pop();

                if (currAmount == amount) {
                    return numOfCoins;
                }

                // push next amount to the q
                for (int currency : coins) {
                    long long nextAmount = (long long)currAmount+(long long)currency;
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