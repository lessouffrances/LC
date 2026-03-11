
//         0 1 2 3 4 5 6
// nums = [1,2,3,4,5,6,7], k = 3
// idx = length-k-1
// [5,6,7,1,2,3,4]

// reverse all:   [7,6,5,4,3,2,1], k = 3
// reverse [0,3): [5,6,7, 4,3,2,1]
// reverse [3,7): [5,6,7,1,2,3,4]

class Solution 
{
    public:
    void rotate(vector<int>& nums, int k) 
    {
        if (nums.empty()) return;
        int n = nums.size();

        // get effective k
        k = k % n;
        if (k == 0) return; // no rotation needed

        // reverse all
        reverse(nums.begin(), nums.end());
        // reverse the [0, k)
        reverse(nums.begin(), nums.begin()+k);
        // rever the [k, end]
        reverse(nums.begin()+k, nums.end());
    }
};