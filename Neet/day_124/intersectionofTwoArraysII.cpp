class Solution 
{
    public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        if (nums1.empty() || nums2.empty()) return {};
        multiset<int> nums1Set(nums1.begin(), nums1.end());

        vector<int> res;
        for (int i=0; i<nums2.size(); i++) {
            if (nums1Set.count(nums2[i])) {
                res.push_back(nums2[i]);
                nums1Set.erase(nums2[i]);
            }
        }
        return res;
    }
};