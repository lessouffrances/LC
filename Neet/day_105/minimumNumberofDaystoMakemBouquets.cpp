










class Solution 
{
    public:
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        if (bloomDay.empty()) return 0;

        if (bloomDay.size() < (long long)m * k) return -1;

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());

        while (left <= right) {
            int daysWait = left + (right - left) / 2;

            if (canMakeBouquets(bloomDay, m, k, daysWait)) {
                right = daysWait-1;
            } else {
                left = daysWait+1;
            }
        }
        return left;
    }
    private:
    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int daysWait)
    {
        int bouquetsMade = 0;
        int flowersBoomed = 0;

        for (int bloom : bloomDay) {
            if (bloom <= daysWait) {
                flowersBoomed++;
                if (flowersBoomed == k) {
                    bouquetsMade++;
                    flowersBoomed = 0; // reset
                }
            } else {
                flowersBoomed = 0;
            }
        }
        return bouquetsMade >= m;
    }
};