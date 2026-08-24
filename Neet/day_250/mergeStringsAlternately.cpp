class Solution 
{
    public:
    string mergeAlternately(string word1, string word2) 
    {
        if (word1.length() == 0) return word2;
        if (word2.length() == 0) return word1;

        int i=0, j=0;
        int m = word1.size(), n = word2.size();
        string res = "";

        while (i<m && j<n) {
            res += word1[i];
            i++;
            res += word2[j];
            j++;
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