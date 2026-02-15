class Solution 
{
    public:
    long long minMoves(vector<int>& balance) 
    {
        if (balance.empty()) return 0;
        int n = balance.size();

        long long posSum = 0;
        int negIdx = -1;
        for (int i=0; i<n; i++) {
            if (balance[i] < 0) {
                negIdx = i;
            } else {
                posSum += balance[i];
            }
        }
        if (negIdx == -1) return 0;
        if (-balance[negIdx] > posSum) return -1;

        long long need = -balance[negIdx];
        long long cost = 0;
        for (int dist=1; dist<n; dist++) {
            long long left = balance[(negIdx-dist+n) % n];
            long long right = balance[(negIdx+dist) % n];

            // left
            long long transferLeft = min(need, left);
            long long leftCost = 1LL * dist * transferLeft;
            need -= transferLeft;

            // right
            long long transferRight = min(need, right);
            long long rightCost = 1LL * dist * transferRight;
            need -= transferRight;

            cost += (leftCost+rightCost);
        }
        return cost;
    }
};