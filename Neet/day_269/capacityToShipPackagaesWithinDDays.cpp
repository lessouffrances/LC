class Solution 
{
    public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        // need a left and right boundary for the binary search
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        while (left < right) {
            int mid = left + (right-left) / 2;
            if (canFinish(mid, weights, days)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }

    private:
    // assume that k is the total capacity of the ship
    bool canFinish(int k, vector<int>& weights, int days)
    {
        int n = weights.size();

        int totalDaysUsed = 1;
        int currWeight = 0;
        for (int i=0; i<n; i++) {
            currWeight += weights[i];
            if (currWeight > k) {
                totalDaysUsed++;
                currWeight = weights[i];
            }
        }
        return totalDaysUsed <= days;
    }
};