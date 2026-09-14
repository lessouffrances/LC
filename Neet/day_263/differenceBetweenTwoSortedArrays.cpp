class Solution
{
    public:
    vector<int> getDiffBetweenTwoSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> res;

        int i = 0, j = 0;
        while (i < m) {
            if (j < n && nums2[j] < nums1[i]) {
                j++;
            } else if (j < n && nums2[j] == nums1[i]) {
                // this nums1 element is "cancelled" by a matching nums2 element
                i++;
                j++;
            } else {
                // either j reached the end of nums2, or nums2[j] > nums1[i]
                res.push_back(nums1[i]);
                i++;
            }
        }
        return res;
    }
};