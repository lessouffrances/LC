







// [1,2,3], k = 3

class Solution 
{
    public:
    int subarraySum(vector<int>& nums, int k) 
    {
        if (nums.empty()) return 0;
        int n = nums.size(); //3

        unordered_map<int, int> prefixSumCounter; //{{0,1},{-2,1},{3,1}}
        prefixSumCounter[0] = 1;
        int prefixSum = 0; //0
        int res = 0; //0 
        for (int i=0; i<n; i++) {
            prefixSum += nums[i]; //1 3 6

            int diff = prefixSum - k; // -2 0 3
            if (prefixSumCounter.count(diff)) {
                res += prefixSumCounter[diff]; //2
            }

            prefixSumCounter[prefixSum]++; //{0,1},{-2,1},{3,1},{6,1}}
        }
        return res; //2
    }
};