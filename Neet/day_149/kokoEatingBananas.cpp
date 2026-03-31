class Solution 
{
    public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        if (piles.empty()) return true;
        int n = piles.size();

        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        while (left <= right) {
            int mid = left + (right-left) / 2;
            if (canFinishAll(piles, h, mid)) {
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
        int n = piles.size();
        long long totalHoursSpent = 0;
        for (int i=0; i<n; i++) {
            totalHoursSpent += (piles[i] + k - 1) / k;
        }
        return totalHoursSpent <= h;
    }
};