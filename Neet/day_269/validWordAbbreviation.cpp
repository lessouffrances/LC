
//         i
// word = "internationalization", 
//         j
// abbr = "i12iz4n"

class Solution 
{
    public:
    bool validWordAbbreviation(string word, string abbr) 
    {
        int m = word.length(), n = abbr.length();
        int i=0, j=0;
        while (i < m && j < n) {
            if (word[i] == abbr[j]) {
                i++;
                j++;
            } else if (isdigit(abbr[j])) {
                // invalid
                if (abbr[j] == '0') return false;
                int num = 0;
                while (j<n && isdigit(abbr[j])) {
                    num = num*10 + (abbr[j]-'0');
                    j++;
                }
                // i should be forward for this many steps
                i += num;
            } else {
                return false;
            }
        }

        return i == m && j == n;
    }
};