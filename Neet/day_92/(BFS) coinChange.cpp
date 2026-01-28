class Solution
{
    public:
    int coinChange(vector<int>& coins, int amount) 
    {
        if (coins.empty() || amount == 0) return 0;

        queue<int> q;
        vector<bool> visited(amount + 1, false);

        q.push(0);
        visited[0] = true;
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            level++;

            for (int i=0; i<size; i++) {
                int currAmount = q.front();
                q.pop();

                for (int coin : coins) {
                    int nextAmount = currAmount + coin;

                    if (nextAmount == amount) {
                        return level;
                    }
                    if (visited[nextAmount] == true) continue;
                    if (nextAmount > amount) continue;
                    visited[nextAmount] = true;
                    q.push(nextAmount);
                }
            }
        }
        return -1;
    }
};