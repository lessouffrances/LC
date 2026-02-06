class Solution 
{
    public:
    long long minMoves(vector<int>& balance) 
    {
        if (balance.empty()) return 0;
        int n = balance.size();

        long long sum = 0;
        for (int bal : balance) {
            sum += bal;
        }
        if (sum < 0) return -1;//impossible

        int bal = balance[0];
        int negIdx = 0;
        for (int i=1; i<n; i++) {
            if (balance[i] < bal) {
                bal = balance[i];
                negIdx = i;
            }
        }
        if (bal >= 0) return 0;// no neg idx

        int need = -bal;
        long long cost = 0;
        for (int dist=1; dist<n; dist++) {
            int left = balance[(negIdx-dist+n) % n];
            int right = balance[(negIdx+dist) % n];

            int transferLeft = min(need, left);
            cost += 1LL * dist * transferLeft;
            need -= transferLeft;

            int transferRight = min(need, right);
            cost += 1LL * dist * transferRight;
            need -= transferRight;
        }
        
        return cost;
    }
};