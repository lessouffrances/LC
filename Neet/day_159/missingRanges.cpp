






class Solution 
{
    public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) 
    {
        if (nums.empty()) return { {lower, upper }};
        int n = nums.size();

        vector<vector<int>> res;
        if (lower < nums[0]) {
            res.push_back( {lower, nums[0]-1} );
        }

        for (int i=0; i<n; i++) {
            // if the adjacent numbers are not consecutive
            if (i+1<n && nums[i+1]-nums[i] != 1) {
                res.push_back( {nums[i]+1, nums[i+1]-1} );
            }
        }

        if (upper > nums[n-1]) {
            res.push_back( {nums[n-1]+1, upper} );
        }
        return res;
    }
};