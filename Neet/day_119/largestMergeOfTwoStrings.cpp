



class Solution 
{
    public:
    string largestMerge(string word1, string word2) 
    {
        if (word1.empty()) return word2;
        if (word2.empty()) return word1;

        int m = word1.length();
        int n = word2.length();
        int i = 0, j = 0;

        string res = "";
        while (i<m && j<n) {
            if (word1.substr(i) > word2.substr(j)) {
                res += word1[i];
                i++;
            } else {
                res += word2[j];
                j++;
            }
        }
        while (i<m) {
            res += word1[i];
            i++;
        }
        while (j<n) {
            res += word2[j];
            j++;
        }
        return res;
    }
};