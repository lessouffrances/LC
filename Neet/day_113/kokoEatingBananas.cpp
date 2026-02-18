class Solution 
{
    public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        if (piles.empty()) return true;

        int right = *max_element(piles.begin(), piles.end());
        int left = 1;
        while (left <= right) {
            int k = left + (right - left)/2;
            if (canFinishAll(piles, h, k)) {
                righ = k-1;
            } else {
                left = k+1;
            }
        }
        return left;
    }
    private:
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