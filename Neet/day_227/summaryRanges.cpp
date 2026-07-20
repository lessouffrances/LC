
// nums = [0,2,3,4,6,8,9]

class Solution 
{
    public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        int i = 0, n = nums.size();
        vector<string> res;

        while (i < n) {
            int start = nums[i];
            while (i+1 < n && (long long)nums[i+1]-nums[i] == 1) i++;
            int end = nums[i];

            if (start == end) {
                res.push_back(to_string(start));
            } else {
                res.push_back(to_string(start) + "->" + to_string(end));
            }
            i++;
        }
        return res;
    }
};