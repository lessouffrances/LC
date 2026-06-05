
// (nums[i] * nums[j]) % k == 0
// iff gcd(nums[i], k) * gcd(nums[j], k) % k == 0

class Solution 
{
    public:
    long long countPairs(vector<int>& nums, int k) 
    {
        if (nums.empty()) return 0;
        unordered_map<long long, int> gcdToCount;

        long long res = 0;
        for (int num : nums) {
            int g = __gcd(num, k);
            for (auto& [gcd, count] : gcdToCount) {
                if (gcd * g % k == 0) {
                    res += count;
                }
            }
            gcdToCount[g]++;
        }
        return res;
    }
};