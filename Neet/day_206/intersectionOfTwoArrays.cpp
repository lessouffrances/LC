class Solution 
{
    public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        if (nums1.empty() || nums2.empty()) return {};

        unordered_set<int>num1Set(nums1.begin(), nums1.end());
        unordered_set<int>num2Set(nums2.begin(), nums2.end());

        vector<int> res;
        for (int num : num1Set) {
            if (num2Set.count(num)) {
                res.push_back(num);
            }
        }
        return res;
    }
};