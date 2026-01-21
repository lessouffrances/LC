class Solution 
{
    public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
    
        vector<vector<int>> res;
        for (int i=0; i<n; i++) {
            if (i-1>=0 && nums[i] == nums[i-1]) continue;

            int diff = 0 - nums[i];
            int l = i+1, r = nums.size()-1;

            while (l < r) {
                if (nums[l] + nums[r] < diff) {
                    l++;
                } else if (nums[l] + nums[r] > diff){
                    r--;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    while ((l+1) < n && nums[l] == nums[l+1]) {
                        l++;
                    }
                    while ((r-1) >=0 && nums[r] == nums[r-1]) {
                        r--;
                    }
                    l++;
                    r--;
                }
            }
        }
        return res;
    }
};
