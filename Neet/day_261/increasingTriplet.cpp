class Solution 
{
    public:
    bool increasingTriplet(vector<int>& nums) 
    {
        if (nums.empty()) return false;

        int first = INT_MAX, second = INT_MAX;
        for (int num : nums) {
            if (num <= first) {
                first = num;
            } else if (num <= second) {
                second = num;
            } else {
                // a num that is > first and > second
                return true;
            }
        }
        return false;
    }
};