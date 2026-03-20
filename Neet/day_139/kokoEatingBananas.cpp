



// Time: O( N log (MAX_ELEMENT_IN_PILES)), where N is the size of the piles
// Space: O(1)
class Solution 
{
    public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        if (piles.empty()) return 0;

        // set ranges for binary search
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left <= right) {
            int mid = left + (right-left) / 2;
            if (canFinishAll(piles, mid, h)) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
    private:
    bool canFinishAll(vector<int>& piles, int k, int h)
    {
        long long totalHoursPassed = 0;
        int n = piles.size();

        for (int i=0; i<n; i++) {
            totalHoursPassed += (piles[i] + k - 1) / k;
        }
        return totalHoursPassed <= h;
    }
};