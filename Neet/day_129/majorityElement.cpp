class Solution 
{
    public:
    int majorityElement(vector<int>& nums) 
    {
        if (nums.empty()) return 0;

        int candidate;
        int count = 0;
        for (int num : nums) {
            // the existence of other elements has offset the count for 
            // this candidate
            if (count == 0) {
                candidate = num;
            } 
            count += (candidate == num) ? 1 : -1;
        }
        return candidate;
    }
};