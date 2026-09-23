// asteroids = [3,5,-6,2,-1,4]​​​​​​​
// stack = [-6,2,4]
class Solution 
{
    public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        int n = asteroids.size();
        stack<int> deck;

        for (int i=0; i<n; i++) {
            int newAster = asteroids[i];
            bool isAlive = true;

            while (!deck.empty() && newAster < 0 && deck.top() > 0) {
                int topAster = deck.top();
                if (abs(newAster) > topAster) {
                    // new alive
                    deck.pop();
                    isAlive = true;
                    continue;
                } else if (abs(newAster) < topAster) {
                    isAlive = false;
                    break; // no longer 
                } else if (abs(newAster) == topAster) {
                    isAlive = false;
                    deck.pop();
                    break;
                }
            }
            if (isAlive) deck.push(newAster);
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
