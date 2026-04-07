




class Solution 
{
    public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) 
    {
        if (nums.empty()) return { {lower, upper} };
        int n = nums.size();

        vector<vector<int>> res;
        // check before the lower
        if (nums[0] > lower) {
            res.push_back( {lower, nums[0]-1} );
        }

        // for the intervals inbetween
        for (int i=0; i<n; i++) {
            if (i+1<n && nums[i+1]-nums[i] != 1) {
                res.push_back( { nums[i]+1, nums[i+1]-1 } );
            }
        }

        // check after the upper
        if (nums[n-1] < upper) {
            res.push_back( {nums[n-1]+1, upper} );
        }
        return res;
    }
};