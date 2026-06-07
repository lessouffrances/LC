class Solution 
{
    public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        if (asteroids.empty()) return {};
        int n = asteroids.size();

        stack<int> deck;
        for (int i=0; i<n; i++) {
            bool isAlive = true;
            while (!deck.empty() && deck.top() > 0 && asteroids[i] < 0) {

                // case 1: newSize > oldSize
                // case 2: newSize < oldSize
                // case 3: same 

                int newSize = -asteroids[i];
                int oldSize = deck.top();

                if (newSize > oldSize) {
                    deck.pop();
                    // continue to the loop, because we want to know if this newOne
                    // will explode other stars on stack too!
                } else if (newSize < oldSize) {
                    isAlive = false;
                    break;
                } else {
                    isAlive = false;
                    deck.pop();
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