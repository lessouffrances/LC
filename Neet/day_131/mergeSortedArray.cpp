class Solution 
{
    public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        // work from right to left
        int pos = m+n-1;
        int i = m-1, j = n-1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[pos] = nums1[i];
                i--;
            } else {
                nums1[pos] = nums2[j];
                j--;
            }

            pos--;
        }

        // if i >= 0
        while (i >= 0) {
            nums1[pos] = nums1[i];
            i--;
            pos--;
        }
        // if j >= 0
        while (j >= 0) {
            nums1[pos] = nums2[j];
            j--;
            pos--;
        }
    }
};