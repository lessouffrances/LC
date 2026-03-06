class Solution 
{
    public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) 
    {
        int n = cars.size();
        vector<double> collisionTimes(n, -1.0);

        // contains the relevant cars ahead:
        // 1. it is possible to catch up
        // 2. the ahead car was not absorbbed yet
        stack<int> deck; 

        for (int i=n-1; i>=0; i--) {
            int currPos = cars[i][0];
            int currSpd = cars[i][1];

            while (!deck.empty()) {
                int aheadIdx = deck.top();
                int aheadPos = cars[aheadIdx][0];
                int aheadSpd = cars[aheadIdx][1];

                // can possibly catch
                if (currSpd > aheadSpd) {
                    // catchTime: gap / relative spd
                    double catchTime = (double)(aheadPos-currPos) / (currSpd-aheadSpd);
                    
                    // can catch:
                    if (collisionTimes[aheadIdx] == -1.0 || catchTime <= collisionTimes[aheadIdx]) {
                        collisionTimes[i] = catchTime; 
                        break;
                    }
                } 
                // cannot catch, the car ahead is irrelevant
                deck.pop();
            }
            // push this car for later use
            deck.push(i);
        }
        return collisionTimes;
    }
};