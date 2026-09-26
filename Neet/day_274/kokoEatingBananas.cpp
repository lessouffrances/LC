class Solution 
{
    public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        // starting left and right?
        int left = 1; 
        int right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = left + (right-left)/2;
            if (canFinish(piles, h, mid)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }

    private:
    bool canFinish(vector<int>& piles, int h, int k)
    {
        int n = piles.size();
        int totalHoursSpent = 0;
        for (int i=0; i<n; i++) {
            totalHoursSpent += (piles[i]+k-1) / k;
        }
        return totalHoursSpent <= h;
    }
};