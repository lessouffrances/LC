class Solution 
{
    public:
    string longestPalindrome(string s) 
    {
        if (s.length() == 0) return "";

        int n = s.length();
        map<int, string> lenToString; // { length : palindromic string }

        for (int start=0; start<n; start++) {
            for (int end=n; end>start; end--) {
                string currStr = string(s.begin()+start, s.begin()+end);
                string reversedCurrStr = currStr;
                reverse(reversedCurrStr.begin(), reversedCurrStr.end());

                if (currStr == reversedCurrStr) {
                    lenToString[(int)currStr.length()] = currStr;
                }
            }
        }

        return lenToString.rbegin()->second;
    }
};