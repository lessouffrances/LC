class Solution 
{
    public:
    vector<int> findCoins(vector<int>& numWays) 
    {
        int n = numWays.size();
        vector<int> res;

        while (true) {
            int c = -1;
            // smallest denomination must have exactly 1 way
            for (int i = 0; i < n; i++) {
                if (numWays[i] == 1) {
                    c = i + 1;
                    break;
                }
            }
            if (c == -1) break;
            res.push_back(c);

            vector<int> old = numWays;
            // remove contribution of coin c
            for (int s=c; s<=n; s++) {
                if (s==c)
                    numWays[s-1] -= 1;   
                else
                    numWays[s-1] -= old[s-c-1];
            }
        }

        // must end with all zeros
        for (int x : numWays) {
            if (x != 0) return {};
        }

        return res;
    }
};