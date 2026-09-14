class Solution 
{
    public:
    bool increasingTriplet(vector<int>& nums) 
    {
        if (nums.empty() || nums.size() < 3) return false;
        int firstMin = INT_MAX, secondMin = INT_MAX;

        for (int num : nums) {
            if (num <= firstMin) {
                firstMin = num;
            } else if (num <=secondMin) {
                secondMin = num;
            } else {
                return true;
            }
        }
        return false;
    }
};