class Solution 
{
    public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        if (piles.empty()) return 0;
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int k = left + (right-left) / 2;
            if (canFinishAll(piles, h, k)) {
                right = k;
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
        long long totalHoursNeeded = 0;

        int n = piles.size();
        for (int i=0; i<n; i++) {
            totalHoursNeeded += (piles[i]+k-1) / k; // ceiling division
        }
        return totalHoursNeeded <= h ? true : false;
    }
};