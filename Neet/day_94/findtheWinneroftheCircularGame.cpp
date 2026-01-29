class Solution 
{
    public:
    int findTheWinner(int n, int k) 
    {
        queue<int> circle;

        // people 1-> n
        for (int i=1; i<=n; i++) {
            circle.push(i);
        }

        while (circle.size() > 1) {
            // move k-1 people at the front to the back
            for (int i=0; i<k-1; i++) {
                circle.push(circle.front());
                circle.pop();
            }
            circle.pop(); // remove the k-th
        }
        return circle.front();
    }
};