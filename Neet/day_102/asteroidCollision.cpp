







// asteroids = [3,5,-6,2,-1,4]​​​​​​​
// stack = [3,]


class Solution 
{
    public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {        
        if (asteroids.empty()) return {};

        stack<int> deck;

        for (int asteroid : asteroids) {
            bool alive = true;

            while (!deck.empty() && asteroid < 0 && deck.top() > 0) {
                int newSize = -asteroid;
                int oldSize = deck.top();

                if (newSize > oldSize) {
                    deck.pop();
                    // continue the while loop
                } else if (newSize == oldSize) {
                    alive = false;
                    deck.pop();
                    break;
                } else if (newSize < oldSize) {
                    alive = false;
                    break;
                }
            }
            if (alive) {
                deck.push(asteroid);
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