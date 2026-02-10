





class Solution 
{
    public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        if (piles.empty()) return 0;

        int right = *max_element(piles.begin(), piles.end());
        int left = 1;

        int k = 0;
        while (left <= right) {
            k = left + (right - left) / 2;
            if (canFinish(piles, h, k)) {
                right = k-1;
            } else {
                left = k+1;
            }
        }
        return left;
    }
    private:
    bool canFinish(vector<int>& piles, int h, int k)
    {
        if (piles.empty()) return true;

        int totalHoursNeeded = 0;
        for (int numOfBanana : piles) {
            totalHoursNeeded += ((numOfBanana + k - 1) / k);
        }
        return totalHoursNeeded <= h;
    }
};