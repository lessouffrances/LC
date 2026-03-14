class Solution 
{
    public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) 
    {
        // cars : {pos, spd}
        int n = cars.size();
        vector<double> collisionTimes(n, -1.0);

        stack<int> deck; // index for relevant cars
        for (int i=n-1; i>=0; i--) {
            int currPos = cars[i][0];
            int currSpd = cars[i][1];

            while (!deck.empty()) {
                int aheadIdx = deck.top();
                int aheadPos = cars[aheadIdx][0];
                int aheadSpd = cars[aheadIdx][1];

                // can possibly catch the ahead car
                if (currSpd > aheadSpd) {
                    double catchTime = (double)(aheadPos - currPos) / (double)(currSpd - aheadSpd);
                    if (collisionTimes[aheadIdx] == -1.0 || catchTime < collisionTimes[aheadIdx]) {
                        collisionTimes[i] = catchTime;
                        break;
                    }
                } else {
                    // impossible to catch up, pop irrelavent cars
                    deck.pop();
                }
                deck.push(i);
            }
            return collisionTimes;
        }
    }
};