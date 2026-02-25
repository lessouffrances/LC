


class Solution 
{
    public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        int m = nums1.size(), n = nums2.size();
        vector<int> res(k, 0);

        for (int k1=max(0, k-n); k1<=min(k, m); k1++) {
            int k2 = k-k1;

            vector<int> sub1 = maxSubsequence(nums1, k1);
            vector<int> sub2 = maxSubsequence(nums2, k2);

            vector<int> merged = merge(sub1, sub2);
            if (merged > res) res = merged;
        }
        return res;
    }
    private:
    // this approach is for preserving the sequence 
    // and also put the largest numbers in advance
    // can be used for min, too
    vector<int> maxSubsequence(vector<int>& nums, int k) 
    {
        if (nums.empty()) return {};
        int n = nums.size();

        int toRemove = n-k; // we can remove this many at most
        vector<int> deck; // use vector as stack

        for (int num : nums) {
            while (!deck.empty() && toRemove > 0 && num > deck.back()) {
                deck.pop_back();
                toRemove--;
            }
            deck.push_back(num);
        }
        return vector<int>(deck.begin(), deck.begin()+k);
    }

    vector<int> merge(vector<int>& a, vector<int>& b) 
    {
        vector<int> res;
        auto i = a.begin(), j = b.begin();

        while (i != a.end() && j != b.end()) {
            // lexicographical_compare returns true if remaining suffix of a < suffix of b
            if (lexicographical_compare(i, a.end(), j, b.end())) {
                res.push_back(*j++);
            } else {
                res.push_back(*i++);
            }
        }

        res.insert(res.end(), i, a.end());
        res.insert(res.end(), j, b.end());
        return res;
    }
};