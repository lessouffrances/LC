class Solution 
{
    public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);
        
        int totalLen = nums1.size() + nums2.size();
        int half = totalLen / 2;
        int n = nums1.size();
        int left = 0, right = n - 1;
        
        while (true) {
            int midA = (left <= right) ? left + (right-left)/2 : -1;
            int midB = half - midA - 2;
            
            double nums1Left  = (midA >= 0) ? nums1[midA] : INT_MIN;
            double nums1Right = (midA+1 < n) ? nums1[midA+1] : INT_MAX;
            double nums2Left  = (midB >= 0) ? nums2[midB] : INT_MIN;
            double nums2Right = (midB+1 < (int)nums2.size()) ? nums2[midB+1] : INT_MAX;
            
            if (nums1Left <= nums2Right && nums2Left <= nums1Right) {
                if (totalLen % 2 == 1) return min(nums1Right, nums2Right);
                return (max(nums1Left, nums2Left) + min(nums1Right, nums2Right)) / 2.0;
            } else if (nums1Left > nums2Right) {
                right = midA - 1;
            } else {
                left = midA + 1;
            }
        }
    }
};