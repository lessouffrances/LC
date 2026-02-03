class Solution 
{
    public:
    int minimizedMaximum(int n, vector<int>& quantities) 
    {
        if (quantities.empty()) return 0;

        int m = quantities.size();
        int left = 1, right = *max_element(quantities.begin(), quantities.end());
        while (left <= right) {
            int k = left + (right-left) / 2;
            if (canDistribute(n, quantities, k, m)) {
                right = k-1;
            } else {
                left = k+1;
            }
        }
        return left;
    }
    private:
    bool canDistribute(int n, vector<int>& quantities, int k, int m)
    {
        long long totalStoresDelivered = 0;
        for (int i=0; i<m; i++) {
            int storesDelivered = (quantities[i] + k - 1) / k;
            totalStoresDelivered += storesDelivered;
        }
        return totalStoresDelivered <= n;
    }
};