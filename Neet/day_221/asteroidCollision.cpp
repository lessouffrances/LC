// asteroids = [3,5,-6,2,-1,4]​​​​​​​
// [-6, 2, 4]

class Solution 
{
    public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        int n = asteroids.size();
        stack<int> deck;
        
        for (int i=0; i<n; i++) {
            bool isAlive = true;
            int newAsteroid = asteroids[i];
            
            // case1: new < 0 && top > 0 and quality(new) > quality(top)
            // case2: new < 0 && top > 0 and quality(new) < quality(top)
            // case2: new < 0 && top > 0 and quality(new) == quality(top)
            while (!deck.empty() && deck.top() > 0 && newAsteroid < 0) {
                int topAsteroid = deck.top();
                if (abs(newAsteroid) > topAsteroid) {
                    deck.pop();
                    isAlive = true;
                    continue;
                } else if (abs(newAsteroid) < topAsteroid) {
                    isAlive = false;
                    break;
                } else if (abs(newAsteroid) == topAsteroid) {
                    deck.pop();
                    isAlive = false;
                    break;
                }
            }

            if (isAlive) {
                deck.push(newAsteroid);
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