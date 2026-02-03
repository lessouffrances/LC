class Solution 
{
    public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        if (piles.empty()) return 0;
        int n = piles.size();
        int left = 1, right = *max_element(piles.begin(), piles.end());
        
        while (left <= right) { 
            int k = left + (right-left) / 2;
            if (canFinish(piles, h, k, n)) {
                right = k-1;
            } else {
                left = k+1;
            }
        }
        return left;
    }
    private:
    bool canFinish(vector<int>& piles, int h, int k, int n)
    {
        long long totalTime = 0;
        for (int i=0; i<n; i++) {
            int timeForCurrentPile = (piles[i] + k - 1) / k;
            totalTime += timeForCurrentPile;
        }   
        
        return totalTime <= h;
    }
};