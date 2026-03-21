


// The feature of this array is only has one drop ** circularly **
// [2,1,3,4], has 2 circular drops, 2 -> 1 drop, 4 -> 2 drop

class Solution 
{
    public:
    bool check(vector<int>& nums) 
    {
        if (nums.empty()) return false;
        int n = nums.size();

        int drops = 0;
        for (int i=0; i<n; i++) {
            if (nums[i] > nums[ (i+1) % n] ) drops++;
            if (drops > 1) return false;
        }
        return true;
    }
};