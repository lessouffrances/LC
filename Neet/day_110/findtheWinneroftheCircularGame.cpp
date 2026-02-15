class Solution 
{
    public:
    int findTheWinner(int n, int k) 
    {
        queue<int> circle;
        for (int i=0; i<n; i++) {
            circle.push(i);
        }

        while (circle.size() > 1) {
            // move k-1 safe friends from front to back of the queue
            for (int i=0; i<k-1; i++) {
                circle.push(circle.front());
                circle.pop();
            }

            // remove the k-th
            circle.pop();
        }
        return circle.front();
    }
};