













class Solution 
{
    public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        unordered_set<int> numSet(arr.begin(), arr.end());

        for (int i=1; i<INT_MAX; i++) {
            if (!numSet.count(i)) {
                k--;
                if (k == 0) {
                    return i;
                }
            }
        }
        return -1;
    }
};