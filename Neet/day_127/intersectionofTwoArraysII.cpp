class Solution 
{
    public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int, int> freq;
        for (int num : nums1) freq[num]++;

        vector<int> res;
        for (int num : nums2) {
            if (freq.count(num)) {
                freq[num]--;
                res.push_back(num);
            } 
        }
        return res;
    }
};