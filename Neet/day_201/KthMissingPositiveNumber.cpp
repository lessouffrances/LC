class Solution 
{
    public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        if (arr.empty()) return 0;

        unordered_set<int>numSet(arr.begin(), arr.end());

        for (int i=0; i<INT_MAX; i++) {
            // is present
            if (numSet.count(i)) continue;

            // is missing
            if (k == 0) return i;
            k--;
        }
        return -1;
    }
};