

class Solution 
{
    public:
    int coinChange(vector<int>& coins, int amount) 
    {
        queue<int> q;
        q.push(0);
        vector<bool> visited(amount+1, false);
        visited[0] = true;

        int numOfCoins = 0;
        while (!q.empty()) {
            int size = q.size();
            
            for (int i=0; i<size; i++) {
                auto currAmount = q.front();
                q.pop();
                
                if (currAmount == amount) return numOfCoins;
                
                for (int coin : coins) {
                    if (currAmount > amount - coin) continue; // prevent addition overflow
                    int nextAmount = currAmount + coin;
                    if (nextAmount > amount) continue;
                    if (visited[nextAmount] == true) continue;

                    visited[nextAmount] = true;
                    q.push(nextAmount);
                }
            }
            numOfCoins++;
        }
        return -1;
    }
};