class Solution 
{
    public:
    vector<int> getConcatenation(vector<int>& nums) 
    {
        vector<int> copyNums = nums;
        int n = copyNums.size();
        for (int i=0; i<n; i++) {
            copyNums.push_back(nums[i]);
        }
        return copyNums;
    }
};
