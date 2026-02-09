class Solution 
{
    public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        if (asteroids.empty()) return {};

        int n = asteroids.size();
        stack<int> deck;
        for (int i=0; i<n; i++) {
            bool alive = true;
            while (!deck.empty() && asteroids[i] < 0 && deck.top() > 0) {
                int newSize = -asteroids[i];
                int oldSize = deck.top();

                if (newSize > oldSize) {
                    deck.pop();
                    // keep the while loop going
                } else if (newSize < oldSize) {
                    alive = false;
                    break; // important break!
                } else {
                    alive = false;
                    deck.pop();
                    break; // important break!
                }
            }
            if (alive) {
                deck.push(asteroids[i]);
            }
        }

        vector<int> res;
        while (!deck.empty()) {
            res.push_back(deck.top());
            deck.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};