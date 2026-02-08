





// a ^ a = 0 (any number XOR itself is 0)
// a ^ 0 = a (any number XOR 0 is itself)

class Solution 
{
    public:
    int singleNumber(vector<int>& nums) 
    {
        if (nums.empty()) return 0;

        int res = 0;
        for (int num : nums) {
            res ^= num;
        }
        return res;
    }
};