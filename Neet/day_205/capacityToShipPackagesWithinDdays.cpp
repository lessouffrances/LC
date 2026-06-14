class Solution 
{
    public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        while (left < right) {
            int mid = left + (right-left) / 2;
            if (canShipWithDdaysUsingCapacity(mid, weights, days)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }

    private:
    bool canShipWithDdaysUsingCapacity(int capacity, vector<int>& weights, int days)
    {
        int realDays = 1;
        int n = weights.size();
        int currWeight = 0;
        for (int i=0; i<n; i++) {
            currWeight += weights[i];
            if (currWeight > capacity) {
                currWeight = weights[i];
                realDays++;
            }
        }
        return realDays <= days;
    }
};