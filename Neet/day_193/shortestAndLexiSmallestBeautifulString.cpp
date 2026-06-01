class Solution 
{
    public:
    string shortestBeautifulSubstring(string s, int k) 
    {
        if (s.length() == 0) return "";
        int windowCountOfOne = 0;
        int minLen = INT_MAX;
        int n = s.size();
        vector<string> collections;

        int left = 0;
        for (int right=0; right<n; right++) {
            if (s[right] == '1') windowCountOfOne++;

            while (windowCountOfOne > k || (windowCountOfOne == k && s[left] == '0')) {
                if (s[left] == '1') windowCountOfOne--;
                left++;
            } 

            // only update the storage when the windowCountOfOne is k
            if (windowCountOfOne == k) {
                int currLen = right-left+1;
                if (currLen < minLen) {
                    minLen = currLen;
                    collections.clear();
                    // as the minLen updates, the previous collections are no longer valid
                }
                if (currLen == minLen) {
                    collections.push_back(s.substr(left, minLen));
                }
            }
        }
s
        sort(collections.begin(), collections.end());
        // sort for lexigraphically smallest
        return !collections.empty() ? collections[0] : "";
    }
};