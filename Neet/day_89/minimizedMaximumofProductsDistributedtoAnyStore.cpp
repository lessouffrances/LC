class Solution 
{
    public:
    int minimizedMaximum(int n, vector<int>& quantities) 
    {
        if (quantities.empty()) return 0;

        int left = 1;
        int right = *max_element(quantities.begin(), quantities.end());

        while (left <= right) {
            int k = left + (right-left)/2;
            if (canDistributeAll(quantities, n, k)) {
                right = k-1;
            } else {
                left = k+1;
            }
        }
        return left;
    }
    private:
    bool canDistributeAll(vector<int>& quantities, int n, int k) 
    {
        if (quantities.empty()) return true;
        int m = quantities.size();

        int totalStoresNeeded = 0;
        for (int i=0; i<m; i++) {
            int storesNeeded = (quantities[i] + k - 1) / k;
            totalStoresNeeded += storesNeeded;
        }
        return totalStoresNeeded <= n;
    }
};