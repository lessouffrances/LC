class Solution 
{
    public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int, int> nextGreater;
        stack<int> deck;

        // build next greater lookup map for nums2
        int n = nums2.size();
        for (int i=0; i<n; i++) {
            while (!deck.empty() && nums2[i] > deck.top()) {
                nextGreater[deck.top()] = nums2[i];
                deck.pop();
            }
            deck.push(nums2[i]);
        }

        // since nums1 is a subset of nums2
        vector<int> res;
        for (int num : nums1) {
            if (nextGreater.count(num)) {
                res.push_back(nextGreater[num]);
            } else {
                res.push_back(-1);
            }
        } 
        return res;
    }
};