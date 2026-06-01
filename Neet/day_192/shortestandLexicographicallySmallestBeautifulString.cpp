


// s = "100011001", k = 3
// Output: "11001"

// 1  0  0  0  1  1  0  0  1
// l
//                r
// minLen = 6

class Solution 
{
    public:
    string shortestBeautifulSubstring(string s, int k) 
    {
        if (s.length() == 0) return "";
        int windowCountOfOne = 0;
        int n = s.size();
        int minLen = 0;
        vector<string> collection;

        int left = 0;
        for (int right=0; right<n; right++) {
            if (s[right] == '1') windowCountOfOne++;
            while (windowCountOfOne > k) {
                if (s[left] == '1') windowCountOfOne--;
                left++;
            }
            if (windowCountOfOne == k) {
                int currLen = right-left+1;
                if (currLen < minLen) {
                    minLen = currLen;
                    collection.clear();
                }
                if (currLen == minLen) {
                    collection.push_back(s.substr(left, minLen));
                }
            }
        }

        sort(collection.begin(), collection.end());
        return !collection.empty() ? collection[0] : "";
    }
};