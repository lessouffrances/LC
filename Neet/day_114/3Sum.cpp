class Solution 
{
    public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        for (int i=0; i<n; i++) {
            if (i-1>=0 && nums[i] == nums[i-1]) continue;

            int diff = -nums[i];
            int left = i+1, right = n-1;
            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum > diff) {
                    right--;
                } else if (sum < diff) {
                    left++;
                } else {
                    // find a triplet
                    res.push_back( {nums[i], nums[left], nums[right]} );

                    // skip 
                    while (left < right && nums[left+1] == nums[left]) left++;
                    while (left < right && nums[right-1] == nums[right]) right--;
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};