class Solution 
{
    public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        if (nums.empty()) return {};

        int n = nums.size();
        vector<int> counter(n+1, 0);
        vector<int> res;
        for (int num : nums) {
            counter[num]++;
            if (counter[num-0] == 2) {
                res.push_back(num);
            }
        }
        return res;
    }
};