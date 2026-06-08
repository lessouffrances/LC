class Solution 
{
    public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        // do the binarySearch on capacity
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        while (left < right) {
            int mid = left + (right-left) / 2;
            if (canShipWithinDaysUsingCapacity(mid, weights, days)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
    private:
    bool canShipWithinDaysUsingCapacity(int capacity, vector<int>& weights, int days)
    {
        int realDays = 1;
        int n = weights.size();
        int currLoad = 0;
        for (int i=0; i<n; i++) {
            currLoad += weights[i];
            if (currLoad > capacity) {
                realDays++;
                currLoad = weights[i];
            }
        }
        return realDays <= days;
    }
};