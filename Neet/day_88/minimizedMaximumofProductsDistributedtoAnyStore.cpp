class Solution 
{
    public:
    int minimizedMaximum(int n, vector<int>& quantities) 
    {
        if (quantities.empty()) return 0;

        // set a range
        int right = *max_element(quantities.begin(), quantities.end());
        int left = 1;

        while (left <= right) {
            int k = left + (right-left) / 2;
            if (canDistribute(n, k, quantities)) {
                right = k-1;
            } else {
                left = k+1;
            }
        }
        return left;
    }
    private:
    bool canDistribute(int n, int k, vector<int>& quantities)
    {
        if (quantities.empty()) return false;
        int m = quantities.size();

        int totalStoreDistributed = 0;
        int currentStoredNeeded = 0;
        for (int i=0; i<m; i++) {
            currentStoredNeeded = (quantities[i] + k - 1) / k;
            totalStoreDistributed += currentStoredNeeded;
        }

        return totalStoreDistributed <= n;
    }
};