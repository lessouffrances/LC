class Solution 
{
    public:
    vector<int> getConcatenation(vector<int>& nums) 
    {
        // nums.insert(nums.end(), nums.begin(), nums,end());
        // return nums;

        vector<int> copy = nums;
        for (int i=0; i<copy.size(); i++) {
            nums.push_back(copy[i]);
        }
        return nums;
    }
};