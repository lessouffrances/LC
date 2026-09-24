class Solution 
{
    public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        unordered_set<int> numsSet(arr.begin(), arr.end());

        for (int i=1; i<INT_MAX; i++) {
            if (numsSet.count(i)) continue;
            k--;
            if (k == 0) return i;
        }
        return -1;
    }
};