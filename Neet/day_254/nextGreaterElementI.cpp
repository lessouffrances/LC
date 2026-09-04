class Solution 
{
    public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        if (nums1.empty() || nums2.empty()) return {};

        stack<int> deck;
        unordered_map<int, int> valToNextGreaterElement;
        int n = nums2.size();
        for (int i=0; i<nums2.size(); i++) {
            while (!deck.empty() && nums2[i] > deck.top()) {
                valToNextGreaterElement[deck.top()] = nums2[i];
                deck.pop();
            }
            deck.push(nums2[i]);
        }

        vector<int> res;
        for (int num : nums1) {
            if (valToNextGreaterElement.count(num)) {
                res.push_back(valToNextGreaterElement[num]);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
};