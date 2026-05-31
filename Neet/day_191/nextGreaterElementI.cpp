
// nums2 = [1,3,4,2]
// deck = [3]
class Solution 
{
    public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        if (nums1.empty() || nums2.empty()) return {};

        // build a map for nums2 map the num to their next greater element in nums2
        unordered_map<int, int> nextGreaterMap;
        stack<int> deck;
        for (int i=0; i<nums2.size(); i++) {
            // keep poping if the nums2[i] is greater than the deck.top()
            while ( !deck.empty() && nums2[i] > nums2[deck.top()] ) {
                nextGreaterMap[nums2[deck.top()]] = nums2[i];
                deck.pop();
            }
            // pop the maximized
            deck.push(i);
        }

        vector<int> res;
        for (int num : nums1) {
            if (nextGreaterMap.count(num)) {
                res.push_back(nextGreaterMap[num]);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
};