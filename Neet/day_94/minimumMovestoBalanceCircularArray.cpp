class Solution 
{
    public:
    long long minMoves(vector<int>& balance) 
    {
        long long sum = 0;
        for (int bal : balance) {
            sum += bal;
        }
        if (sum < 0) return -1;

        int n = balance.size();
        int bal = balance[0];
        int mostNegIdx = 0;
        for (int i=1; i<n; i++) {
            if (balance[i] < bal) {
                mostNegIdx = i;
                bal = balance[i];
            }
        }
        if (bal >= 0) return 0;

        int need = -bal;
        long long cost = 0;
        for (int dist=1; dist<n; dist++) {
            int left = balance[(mostNegIdx - dist + n) % n];
            int right = balance[(mostNegIdx + dist) % n];

            int transferLeft = min(left, need);
            need -= transferLeft;
            cost += 1LL * dist * transferLeft;

            int transferRight = min(right, need);
            need -= transferRight;
            cost += 1LL * dist * transferRight;
        }
        return cost;
    }
};
