



// Time: O(N)
// Space: O(1)

class Solution 
{
    public:
    int majorityElement(vector<int>& nums) 
    {
        if (nums.empty()) return 0;

        int candidate = 0;
        int count = 0;
        for (int num : nums) {
            // has been offset
            if (count == 0) {
                candidate = num;
            } 
            count += (candidate == num) ? 1 : -1;
        }
        return candidate;
    }
};