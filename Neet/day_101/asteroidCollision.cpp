




// [3,5,-6,2,-1,4]

// deck = [-6,2,4]

class Solution 
{
    public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        if (asteroids.empty()) return {};
        int n = asteroids.size();

        stack<int> deck;
        for (int asteroid : asteroids) {
            bool alive = true;

            while (!deck.empty() && asteroid < 0 && deck.top() > 0) {
                int topSize = deck.top();
                int newSize = abs(asteroid);

                if (newSize > topSize) {
                    deck.pop();
                } else if (newSize == topSize) {
                    deck.pop();
                    alive = false;
                    break;
                } else {
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