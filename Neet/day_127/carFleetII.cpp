class Solution 
{
    public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) 
    {
        int n = cars.size();
        vector<double> collisionTimes(n, -1.0);

        stack<int> relevantCars; // stores indexes of cars that haven't been caught up yet

        // process from right to left 
        // in case we always want to know what's ahead
        for (int i=n-1; i>=0; i--) {
            int currPos = cars[i][0];
            int currSpd = cars[i][1];

            while (!relevantCars.empty()) {
                
                
            }
        }
    }
}