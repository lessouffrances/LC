// nums[i] * nums[j] is divisible by k 
// iff gcd(nums[i], k) * gcd(nums[j], k) is divisible by k
class Solution 
{
    public:
    long long countPairs(vector<int>& nums, int k) 
    {
        if (nums.empty()) return 0;

        unordered_map<long long, int> gcdCount;

        long long res = 0;
        for (int num : nums) {
            int g = __gcd(num, k);
            for (auto& [prevGcd, count] : gcdCount) {
                if ((long long) g * prevGcd % k == 0) {
                    res += count;
                }
            }
            gcdCount[g]++;
        } 
        return res;
    }
};