=class Solution 
{
    public:
    int minimizedMaximum(int n, vector<int>& quantities) 
    {
        if (quantities.empty()) return 0;
        int right = *max_element(quantities.begin(), quantities.end());
        int left = 1;

        int x = 0;
        while (left <= right) {
            x = left + (right - left) / 2;
            if (canCoverAllStores(n, quantities, x)) {
                right = x-1;
            } else {
                left = x+1;
            }
        }
        return left;
    }
    private:
    bool canCoverAllStores(int n, vector<int>& quantities, int x)
    {
        int totalStoresCovered = 0;
        for (int quantity : quantities) {
            totalStoresCovered += (quantity + x - 1) / x;
        }
        return totalStoresCovered <= n;
    }
};