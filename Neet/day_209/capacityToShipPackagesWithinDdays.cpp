class Solution 
{
    public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        if (weights.empty()) return 0;

        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        while (left < right) {
            int mid = left + (right-left) / 2;
            if (canFinishAllShippingWithDdays(mid, weights, days)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
    private:
    bool canFinishAllShippingWithDdays(int cap, vector<int>& weights, int days)
    {
        int realDays = 1;
        int currLoad = 0;
        for (int i=0; i<weights.size(); i++) {
            currLoad += weights[i];
            if (currLoad > cap) {
                currLoad = weights[i];
                realDays++;
            }
        }
        return realDays <= days;
    }
};