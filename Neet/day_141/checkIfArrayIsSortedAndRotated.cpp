



// the feature of this type of array:
// Circularly, there is only one drop.

// [2,1,4,3] has 2 circular drops:
// 2 -> 1 is one drop
// 3 -> 2 is another circular drop

class Solution 
{
    public:
    bool check(vector<int>& nums) 
    {
        if (nums.empty()) return false;
        int n = nums.size();

        int drops = 0;
        for (int i=0; i<n; i++) {
            if (nums[(i+1) % n] < nums[i]) drops++;
            if (drops > 1) return false; 
        }
        return true;
    }
};