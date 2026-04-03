


//         0 1 2 3 4 5 6
// nums = [1,2,3,4,5,6,7], k = 3
// [5,6,7,1,2,3,4]

class Solution 
{
    public:
    void rotate(vector<int>& nums, int k) 
    {
        if (nums.empty()) return;
        int n = nums.size();

        // get effective k
        k = k % n;

        vector<int> rotated;
        rotated.insert(rotated.end(), nums.begin()+n-k, nums.end());
        rotated.insert(rotated.end(), nums.begin(), nums.begin()+n-k);
        nums = rotated;

        return;
    }
};