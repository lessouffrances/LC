class Solution 
{
    public:
    // asteroids = [3,5,-6,2,-1,4]​​​​​​​, exp = [-6,2,4]
    // stack = [-6,2,4]
    // when would this collision happen?
    // iff
    // deck.top() -> right
    // new Item <- left
    // and the size(new Item) > size(deck.top()) 
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        if (asteroids.empty()) return {};
        int n = asteroids.size();
        stack<int> deck;
        for (int i=0; i<n; i++) {
            bool isAlive = true;
            while (!deck.empty() && deck.top()>0 && asteroids[i]<0) {
                int newSize = -asteroids[i];
                int oldSize = deck.top();
                if (newSize > oldSize) {
                    deck.pop();
                    // continue the loop
                } else if (newSize < oldSize) {
                    isAlive = false;
                    break;
                } else {
                    deck.pop();
                    isAlive = false;
                    break;
                }
            }
            if (isAlive) {
                deck.push(asteroids[i]);
            }
        }

        // evaluate the stack
        vector<int> res;
        while (!deck.empty()) {
            res.push_back(deck.top());
            deck.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};