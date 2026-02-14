class Solution 
{
    public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        // build nextGreater for nums2
        int n = nums.size();
        stack<int> deck;
        unordered_map<int, int> nextGreater;
        for (int i=0; i<n; i++) {
            while (!deck.empty() && nums2[i]> nums2[deck.top()]) {
                auto prevIdx = deck.top();
                deck.pop();

                nextGreater[nums2[prevIdx]] = nums2[i];
            }
            deck.push(i);
        }

        vector<int> res;
        for (int num : nums1) {
            res.push_back(nextGreater[num]);
        }
        return res;
    }
};