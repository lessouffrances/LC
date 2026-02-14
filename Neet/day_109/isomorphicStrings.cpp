class Solution 
{
    public:
    bool isIsomorphic(string s, string t) 
    {
        if (s.length() != t.length()) return false;
        int n = s.length();

        unordered_map<char, char> sTot;
        unordered_map<char, char> tTos;

        for (int i=0; i<n; i++) {
            char sCh = s[i];
            char tCh = t[i];

            if (sTot.count(sCh)) {
                if (tCh != sTot[sCh]) return false;
            } else {
                sTot[sCh] = tCh;
            }
            if (tTos.count(tCh)) {
                if (sCh != tTos[tCh]) return false;
            } else {
                tTos[tCh] = sCh;
            }
        }
        return true;
    }
};