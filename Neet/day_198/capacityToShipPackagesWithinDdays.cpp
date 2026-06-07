class Solution 
{
    public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        while (left < right) {
            int mid = left + (right-left) / 2;
            if (canAchieveWithinDdays(mid, days, weights)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }

    private:
    //                    i
    // [1,2,3,4,5,6,7,8,9,10], cap = 12
    bool canAchieveWithinDdays(int capacity, int days, vector<int>& weights)
    {
        int realDays = 1;
        int n = weights.size();
        int currLoad = 0;
        for (int i=0; i<n; i++) {
            currLoad += weights[i];
            if (currLoad > capacity) {
                currLoad = weights[i];
                realDays++;
            }
        }
        return realDays<=days;
    }
};