class Solution 
{
    public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        int n = nums.size();
        vector<int> res;

        // recorder is the nums, and the source is also nums
        for (int i=0; i<n; i++) {
            // use the num as index
            int index = abs(nums[i]) - 1;

            // have I visited this index before?
            if (nums[index] < 0) {
                // 
                result.push_back(index + 1);
            } else {
                // if visited for the first time, do:
                nums[index] = -nums[index];
            }
        }
        return result;
    }
};