class Solution 
{
    public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        if (nums1.empty() || nums2.empty()) return {};
        int m = nums1.size();
        int n = nums2.size();

        unordered_map<int, int> numToIdx;
        unordered_map<int, int> idxToNum;
        for (int i=0; i<n; i++) {
            numToIdx[nums2[i]] = i;
        }

        vector<int> res;
        for (int i=0; i<m; i++) {
            int idxInNums2 = numToIdx[nums1[i]];
            bool found = false;
            for (int j=idxInNums2+1; j<n; j++) {
                if (nums2[j] > nums1[i]) {
                    res.push_back(nums2[j]);
                    found = true;
                    break;
                }
            }
            if (!found) {
                res.push_back(-1);
            }
        }
        
        return res;
    }
};