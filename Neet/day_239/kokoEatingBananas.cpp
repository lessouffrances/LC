class Solution 
{
    public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        // left and right range
        int left = 1, right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = left + (right-left) / 2;

            if (canFinishEatingAllBananas(piles, h, mid)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }

    private:
    bool canFinishEatingAllBananas(vector<int>& piles, int h, int k)
    {
        int hours = 0;
        int n = piles.size();

        for (int i=0; i<n; i++) {
            hours += (piles[i] + k - 1) / k; // ceiling division
        }
        return hours <= h;
    }
};