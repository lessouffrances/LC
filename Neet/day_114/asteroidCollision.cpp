





// asteroids = [3,5,-6,2,-1,4]​​​​​​​, exp = [-6,2,4]
// deck = -6,2,4
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
            while (!deck.empty() && deck.top() > 0 && asteroids[i] < 0) {
                int newSize = -asteroids[i];
                int oldSize = deck.top();

                if (newSize > oldSize) {
                    deck.pop(); // old explode
                } else if (newSize < oldSize) {
                    alive = false; // new explode
                    break;
                } else {
                    deck.pop();
                    alive = false; // both explode
                    break;
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