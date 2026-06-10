
// nums2 = [1,4,3,2]
// deck = 
class Solution 
{
    public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        if (nums1.empty() || nums2.empty()) return {};

        // for nums2
        // only those have next greater element would be in this map
        unordered_map<int, int> valToNextGreatElement;
        stack<int> deck;
        int n = nums2.size();

        for (int i=0; i<n; i++) {
            while (!deck.empty() && nums2[i] > deck.top()) {
                valToNextGreatElement[deck.top()] = nums2[i];
                deck.pop();
            }
            deck.push(nums2[i]);
        }

        // populate the res
        vector<int> res;
        for (int num : nums1) {
            if (valToNextGreatElement.count(num)) {
                res.push_back(valToNextGreatElement[num]);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
};