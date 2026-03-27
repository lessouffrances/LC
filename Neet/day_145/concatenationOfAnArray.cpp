
// Time: O(n)
// Space: O(n)

class Solution 
{
    public:
    vector<int> getConcatenation(vector<int>& nums) 
    {
        vector<int> copyNums = nums;
        for (int num : copyNums) {
            nums.push_back(num);
        }
        return nums;
    }
};