


// Time: O(N)
// Space: O(N)

class Solution 
{
    public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) 
    {
        // the cars are already be sorted in descending order in pos
        int n = cars.size();
        vector<double> collisionTimes(n, -1.0); // -1 means has not collided

        stack<int> deck; 
        for (int i=n-1; i>=0; i--) {
            int currPos = cars[i][0];
            int currSpd = cars[i][1];

            while (!deck.empty()) {
                int aheadIdx = deck.top();
                int aheadPos = cars[aheadIdx][0];
                int aheadSpd = cars[aheadIdx][1];

                // can possibly catch: important condition 1
                if (currSpd > aheadSpd) {
                    // catchTime: gap / relative spd
                    double catchTime = (double)(aheadPos-currPos) / (currSpd-aheadSpd);

                    // can catch
                    if (collisionTimes[aheadIdx] == -1.0 || catchTime < collisionTimes[aheadIdx]) {
                        collisionTimes[i] = catchTime;
                        break;
                    }
                }
                // impossible to catch
                deck.pop();
            }
            // push this car for later use
            deck.push(i);
        }
        return collisionTimes;
    }
};