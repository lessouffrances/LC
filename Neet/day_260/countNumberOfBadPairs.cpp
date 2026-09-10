// bad pairs: j > i and j-i != nums[j]-nums[i]
// good pairs: j > i and j-i == nums[j]-nums[i]

class Solution 
{
    public:
    long long countBadPairs(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();
        // count the number of good pairs
        // answers the freq of nums[i]-i
        unordered_map<int, int> lookup;

        long long good = 0;
        for (int i=0; i<n; i++) { 
            int key = nums[i]-i;
            if (lookup.count(key)) {
                good += lookup[key];
            }
            lookup[key]++;
        }
        // divided by 2 to avoid double counting
        return (long long)n*(n-1)/2 - good;
    }
};