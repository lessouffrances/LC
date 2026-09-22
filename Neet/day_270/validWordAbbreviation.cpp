
// word = "internationalization", 
// abbr = "i12iz4n"

class Solution 
{
    public:
    bool validWordAbbreviation(string word, string abbr) 
    {
        int i=0, j=0;
        int m = word.length(), n = abbr.length();

        while (i<m && j<n) {
            // if digits appear in abbr
            if (j<n && isdigit(abbr[j])) {
                string currNumStr = "";
                while (j<n && isdigit(abbr[j])) {
                    currNumStr += abbr[j];
                    j++;
                }
                if (currNumStr[0] == '0') return false;
                int currNum = stoi(currNumStr);
                i += currNum;
            } else if (word[i] == abbr[j]) {
                i++;
                j++;
            } else {
                return false;
            }
        }
        return i == m && j == n;
    }
};