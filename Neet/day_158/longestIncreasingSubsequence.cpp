





// nums = [10,9,2,5,3,7,101,18]

class Solution 
{
    public:
    int lengthOfLIS(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int n = nums.size();

        unordered_map<int, int> lookUp; // { idx, length LIS ends with idx }

        int res = 1;
        lookUp[0] = 1;
        for (int i=1; i<n; i++) {
            // can always initiate with 1
            lookUp[i] = 1;
            // check the map 
            for (int j=0; j<i; j++) {
                if (lookUp.count(j) && nums[j] < nums[i]) {
                    lookUp[i] = max(lookUp[i], lookUp[j] + 1);
                    res = max(lookUp[i], res);
                }
            }
        }
        return res;
    }
};