class Solution 
{
    public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        if (piles.empty()) return true;
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left <= right) {
            int k = left + (right-left) / 2;
            if (canFinishAll(piles, h, k)) {
                right = k-1;
            } else {
                left = k+1;
            }
        }
        return left;
    }
    private:
    bool canFinishAll(vector<int>& piles, int h, int k)
    {
        if (piles.empty()) return true;

        int n = piles.size();
        long long totalTimeNeeded = 0;
        for (int i=0; i<n; i++) {
            long long timeNeededForThisPile = (piles[i] + k - 1) / k;
            totalTimeNeeded += timeNeededForThisPile;
        }
        return totalTimeNeeded <= h;
    }
};
