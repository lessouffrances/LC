class Solution 
{
    public:
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        // we will need m * k flowers in total
        if (bloomDay.size() < (long long)m * k) return -1;

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());

        while (left < right) {
            int mid = left + (right-left)/2;
            if (canMakeMbouquetsWithinDays(mid, bloomDay, m, k)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }

    private:
    bool canMakeMbouquetsWithinDays(int daysWait, vector<int>& bloomDay, int m, int k)
    {
        int totalBouquetsMade = 0;
        int currNumOfFlowers = 0;
        for (int i=0; i<bloomDay.size(); i++) {
            if (bloomDay[i] <= daysWait) {
                currNumOfFlowers++;
            } else {
                currNumOfFlowers = 0;
            }

            if (currNumOfFlowers == k) {
                totalBouquetsMade++;
                currNumOfFlowers = 0;
            }
        }
        return totalBouquetsMade >= m;
    }
};