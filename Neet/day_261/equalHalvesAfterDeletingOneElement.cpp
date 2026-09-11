class Solution
{
    public:
    bool equalHalves(vector<int>& nums)
    {
        if (nums.size() <= 2) return false;

        int total = accumulate(nums.begin(), nums.end(), 0);
        unordered_map<int> leftMap;
        unordered_map<int> rightMap;

        for (int& num : nums) rightMap[num]++;

        int leftSum = 0;
        for (int& num : nums) {
            leftSum += num;
            int rightSum = total - leftSum;
            // num moves to the left half
            leftMap[num]++;
            rightMap[num]--;

            int diff = leftSum - rightSum;
            if (leftMap[diff] >= 1 || rightMap[-diff] >= 1) return true;
        }
        return false;
    }
};