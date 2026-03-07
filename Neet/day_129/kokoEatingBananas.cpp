class Solution 
{
    public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int right = *max_element(piles.begin(), piles.end());
        int left = 1;

        while (left <= right) {
            int mid = left + (right-left) / 2;

            if (canFinishAll(piles, h, mid)) {
                // use this spdmid, koko can finish all bananas => looks for lower spd
                right = mid-1;
            } else {
                // can not finish all bananas using spd mid
                left = mid+1;
            }
        }
        return left;
    }
    private:
    // if eat k bananas per hour, can we finish all piles in h hours ?
    bool canFinishAll(vector<int>& piles, int h, int k)
    {
        long long totalHoursSpent = 0;
        int n = piles.size();
        for (int i=0; i<n; i++) {
            totalHoursSpent += (piles[i] + k - 1) / k;
        }
        return totalHoursSpent <= h;
    }
};