class Solution 
{
    public:
    int findTheWinner(int n, int k) 
    {
        queue<int> q;
        // push all n friends onto the q
        for (int i=1; i<=n; i++) {
            q.push(i);
        }

        while (q.size() > 1) {
            // move the k friends at front to the back
            for (int i=0; i<k-1; i++) {
                q.push(q.front());
                q.pop(); // this pop is front
            }

            // pop the k-th friend
            q.pop();
        }
        return q.front();
    }
};