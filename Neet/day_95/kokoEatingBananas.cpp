class Solution 
{
    public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        if (piles.empty()) return 0;
        int maxK = *max_element(piles.begin(), piles.end());
        int left = 1, right = maxK;

        while (left <= right) {
            int mid = left + (right-left) / 2;
            if (canFinishAll(piles, h,mid)) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
    private:
    bool canFinishAll(vector<int>& piles, int h, int k)
    {
        if (piles.empty()) return true;
        int n = piles.size();
        
        long long totalTimeSpent = 0;
        for (int i=0; i<n; i++) {
            long long timeForPile = (piles[i] + k - 1) / k;
            totalTimeSpent += timeForPile;
        } 
        return totalTimeSpent <= h;
    }
}: