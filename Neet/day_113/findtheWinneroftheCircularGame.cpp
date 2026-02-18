class Solution 
{
    public:
    int findTheWinner(int n, int k) 
    {
        queue<int> q;
        for (int i=1; i<=n; i++) {
            q.push(i);
        }

        while (q.size() > 1) {
            // move the k-1 people to the back
            for (int i=0; i<k-1; i++) {
                q.push(q.front());
                q.pop();
            }

            // pop the k-th
            q.pop();
        }
        return q.front();
    }
};