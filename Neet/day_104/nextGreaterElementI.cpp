







class Solution 
{
    public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        if (nums1.empty() || nums2.empty()) return {};

        // build map for nextGreater for nums2
        unordered_map<int, int> nextGreater; // num : nextGreaterNum
        stack<int> deck;

        for (int num : nums2) {
            while (!deck.empty() && deck.top() < num) {
                nextGreater[deck.top()] = num;
                deck.pop();
            }
            deck.push(num);
        }

        vector<int> ans;
        for (int num : nums1) {
            ans.push_back( nextGreater.count(num) ? nextGreater[num] : -1 );
        }

        return ans;
    }
};