class Solution 
{
    public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        if (nums.empty()) return 0;

        // groupr subarrays by remainder mod k
        unordered_map<int, int> remainderCount;
        remainderCount[0] = 1;
 
        int currSum = 0;
        int count = 0;
        for (int num : nums) {
            currSum += num;
            int remainder = ((currSum % k) + k) % k; // normalize
            count += remainderCount[remainder];

            remainderCount[remainder]++;
        }
        return count;
    }
};