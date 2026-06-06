class Solution 
{
    public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int n = weights.size();

        // left should be set at maxItem size
        int maxItem = *max_element(weights.begin(), weights.end());
        int left = maxItem;

        // right should be the total weight
        long long right = 0;
        for (int w : weights) {
            right += w;
        }

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canAchieveWithDays(mid, days, weights)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }

    private:
    //                    i
    // weights = [1,2,3,4,5,6,7,8,9,10], capacity = 6
    // currLoad = 5,
    // realDays = 2
    bool canAchieveWithDays(int capacity, int days, vector<int>& weights)
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
        return realDays <= days;
    }
};